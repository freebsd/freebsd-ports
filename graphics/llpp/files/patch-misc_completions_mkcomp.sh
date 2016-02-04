--- misc/completions/mkcomp.sh.orig	2015-10-13 20:12:27 UTC
+++ misc/completions/mkcomp.sh
@@ -7,7 +7,7 @@ parse_infile () {
     # Output list of file extensions from all input files, one per line.
     # Delete lines beginning with `#', empty lines, and strip leading and
     # trailing whitespace.
-    sed -f - <<EOF $@
+    gsed -f - <<EOF $@
 /^#/d
 /^[[:space:]]*$/d
 s/^[[:space:]]+//g
@@ -43,5 +43,5 @@ if test "$(basename "$f")" = llppac; the
 fi
 re="$(print_regex llpp.in $llppac)"
 
-sed -e "s/@re@/$re/g" "$f.mk" > "$f"
+gsed -e "s/@re@/$re/g" "$f.mk" > "$f"
 printf "wrote: %s\n" "$f"
