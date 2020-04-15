--- scripts/linux/package-vst3.sh.orig	2020-04-15 18:28:12 UTC
+++ scripts/linux/package-vst3.sh
@@ -15,4 +15,6 @@ fi
 
 VST_SO_DIR="$BUNDLE_DIR/Contents/x86_64-linux"
 mkdir -p "$VST_SO_DIR"
-cp build/libsurge-vst3.so "$VST_SO_DIR"/Surge.so
+cp ../.build/libsurge-vst3.so "$VST_SO_DIR"/Surge.so
+
+echo "package-vst3.sh is done"
