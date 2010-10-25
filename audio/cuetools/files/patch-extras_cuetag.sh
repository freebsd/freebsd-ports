--- extras/cuetag.sh.orig	2006-02-14 19:10:02.000000000 -0500
+++ extras/cuetag.sh	2010-10-24 03:20:01.349578391 -0400
@@ -18,7 +18,7 @@
 {
 	# FLAC tagging
 	# --remove-vc-all overwrites existing comments
-	METAFLAC="metaflac --remove-vc-all --import-vc-from=-"
+	METAFLAC="metaflac --remove-all-tags --import-tags-from=-"
 
 	# Ogg Vorbis tagging
 	# -w overwrites existing comments
@@ -63,7 +63,7 @@
 	(for field in $fields; do
 		value=""
 		for conv in `eval echo \\$$field`; do
-			value=`$CUEPRINT -n $1 -t "$conv\n" $cue_file`
+			value=`$CUEPRINT -n $1 -t "$conv\n" "$cue_file"`
 
 			if [ -n "$value" ]; then
 				echo "$field=$value"
@@ -96,7 +96,7 @@
 	for field in $fields; do
 		value=""
 		for conv in `eval echo \\$$field`; do
-			value=`$CUEPRINT -n $1 -t "$conv\n" $cue_file`
+			value=`$CUEPRINT -n $1 -t "$conv\n" "$cue_file"`
 
 			if [ -n "$value" ]; then
 				break
@@ -141,14 +141,14 @@
 	cue_file=$1
 	shift
 
-	ntrack=`cueprint -d '%N' $cue_file`
+	ntrack=`cueprint -d '%N' "$cue_file"`
 	trackno=1
 
 	if [ $# -ne $ntrack ]; then
 		echo "warning: number of files does not match number of tracks"
 	fi
 
-	for file in $@; do
+	for file in "$@"; do
 		case $file in
 		*.[Ff][Ll][Aa][Cc])
 			vorbis $trackno "$file"
@@ -160,7 +160,7 @@
 			id3 $trackno "$file"
 			;;
 		*)
-			echo "$file: uknown file type"
+			echo "$file: unknown file type"
 			;;
 		esac
 		trackno=$(($trackno + 1))
