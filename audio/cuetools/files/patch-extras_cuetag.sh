--- extras/cuetag.sh.orig	2008-11-28 00:41:26.000000000 +0300
+++ extras/cuetag.sh	2008-11-28 00:41:32.000000000 +0300
@@ -18,7 +18,7 @@
 {
 	# FLAC tagging
 	# --remove-vc-all overwrites existing comments
-	METAFLAC="metaflac --remove-vc-all --import-vc-from=-"
+	METAFLAC="metaflac --remove-all-tags --import-tags-from=-"
 
 	# Ogg Vorbis tagging
 	# -w overwrites existing comments
