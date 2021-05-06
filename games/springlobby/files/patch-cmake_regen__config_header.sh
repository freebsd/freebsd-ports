--- cmake/regen_config_header.sh.orig	2019-12-13 00:25:26 UTC
+++ cmake/regen_config_header.sh
@@ -11,7 +11,7 @@ set -u
 SOURCE="$1"
 OUTPUT="$2"
 
-REV="$(git -C "$SOURCE" describe --tags)" 2>/dev/null
+REV=
 
 if [ -z "$REV" ]; then
 	REV="unknown"
