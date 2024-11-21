--- scripts/prep-fle-addon.sh.orig	2024-05-13 17:26:57 UTC
+++ scripts/prep-fle-addon.sh
@@ -62,7 +62,7 @@ if [ x"$PREBUILT_OSNAME" != x"" ]; then
   mv -v prebuilts/nocrypto/include include
   mv -v prebuilts/$LIB/*bson* lib
   rm -rf prebuilts
-else
+elif [ `uname` != FreeBSD ]; then
   if [ `uname` = Darwin ]; then
     export CFLAGS="-mmacosx-version-min=10.15";
   fi
@@ -86,7 +86,7 @@ else
   cd ../../
 fi
 
-if [ x"$FLE_NODE_SOURCE_PATH" != x"" ]; then
+if [ x"$FLE_NODE_SOURCE_PATH" != x"" -a `uname` != FreeBSD -a "$BUILD_TYPE" != dynamic ]; then
   mkdir -p "$FLE_NODE_SOURCE_PATH"/deps/lib
   mkdir -p "$FLE_NODE_SOURCE_PATH"/deps/include
   cp -rv "$BUILDROOT"/lib*/*-static* "$FLE_NODE_SOURCE_PATH"/deps/lib
