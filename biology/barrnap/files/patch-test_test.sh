--- test/test.sh.orig	2026-04-13 08:23:19 UTC
+++ test/test.sh
@@ -4,8 +4,8 @@ setup () {
   bats_require_minimum_version 1.5.0
   dir=$(dirname "$BATS_TEST_FILENAME")
   cd "$dir"
-  cpus=$(nproc)
-  exe="$dir/../bin/barrnap --threads $cpus"
+  cpus=${CPUS:-$(sysctl -n hw.ncpu)}
+  exe="$dir/../bin/barrnap --threads $cpus --dbdir $dir/../db"
   dbs="bac arc fun"
   tab=$'\t'
   TRNA="${tab}tRNA${tab}"
@@ -14,6 +14,18 @@ setup () {
   OPERON="${tab}operon${tab}"
   SEQREG="##sequence-region"
 }
+
+require_cmds() {
+  local cmd
+  for cmd in "$@"; do
+    command -v "$cmd" >/dev/null || skip "missing required command: $cmd"
+  done
+}
+
+require_db_models() {
+  find "$dir/../db" -name '*.cm' -print -quit | grep -q . || skip "missing bundled CM models"
+}
+
 @test "Script syntax check" {
   run -0 perl -c "$dir/../bin/barrnap"
 }
@@ -47,33 +59,42 @@ setup () {
   [[ "$output" =~ "--kingdom" ]]
 }
 @test "Null input" {
+  require_cmds cmsearch seqkit
   run ! $exe null.fa
   [[ "$output" =~ "ERROR" ]]
 }
 @test "Empry input" {
+  require_cmds cmsearch seqkit
   run ! $exe empty.fa
   [[ "$output" =~ "ERROR" ]]
 }
 @test "Weird poly-G sequence" {
+  require_cmds cmsearch seqkit
+  require_db_models
   run -0 $exe --fast polyg.fa
   [[ "$output" =~ "Found 0 features" ]]
 }
 @test "Input with no hits" {
+  require_cmds cmsearch seqkit
+  require_db_models
   run -0 $exe nohits.fa
   [[ "$output" =~ "Found 0 features" ]]
 }
 @test "Fast mode" {
+  require_cmds cmsearch seqkit
+  require_db_models
   run -0 $exe -q --fast small.fa
   [[ "$output" =~ $RRNA ]]
 }
 @test "Mini bacterial genome" {
+  require_cmds aragorn bedtools cmsearch cmscan diamond pyrodigal seqkit taxonkit transterm ziggypep
   local outseq="${BATS_TMPDIR}/outseq.fa"
   run -0 $exe --all --quiet \
     --outseq "$outseq" \
     --incseqreg --incseq --addids \
     small.fa
   [[ "$output" =~ $TRNA ]]
-  [[ "$output" =~ $RRMA ]]
+  [[ "$output" =~ $RRNA ]]
   [[ "$output" =~ $NCRNA ]]
   [[ "$output" =~ "ID=5S" ]]
   [[ "$output" =~ "ID=16S" ]]
@@ -90,9 +111,11 @@ barrnap_legacy() {
 }
 
 barrnap_legacy() {
+  require_cmds cmsearch seqkit
+  require_db_models
   run -0 $exe --quiet \
     --kingdom "$1" "$1.fa"
-  [[   "$output" =~ $RRMA  ]]
+  [[   "$output" =~ $RRNA  ]]
   [[ ! "$output" =~ $TRNA  ]]
   [[ ! "$output" =~ $NCRNA ]]
   [[ ! "$output" =~ "##FASTA" ]]
@@ -100,6 +123,8 @@ barrnap_legacy() {
   [[ ! "$output" =~ "ID=" ]]
 }
 @test "Bacteria" {
+  require_cmds cmsearch seqkit
+  require_db_models
   #type barrnap_legacy
   run barrnap_legacy "bac"
   #echo "STATUS=$status" >&3
@@ -108,10 +133,14 @@ barrnap_legacy() {
   #[[ "$FOO" =~ "5S_rRNA" ]]
 }
 @test "Archaea" {
+  require_cmds cmsearch seqkit
+  require_db_models
   run -0 barrnap_legacy "arc"
   #[[ "$output" =~ "5S_rRNA" ]]
 }
 @test "Fungi" {
+  require_cmds cmsearch seqkit
+  require_db_models
   run -0 barrnap_legacy "fun"
   #[[ "$output" =~ "28S_rRNA" ]]
 }
