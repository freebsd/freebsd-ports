--- make.sh.orig	2026-11-07 16:04:52 UTC
+++ make.sh
@@ -23,6 +23,10 @@ if [ "$OS" == "mac" ]; then
   if [ "$ARCH" == "x86_64" ]; then
     cFlags+=" --target=x86_64-apple-darwin18.7.0"
   fi
+elif [ "$OS" == "freebsd" ]; then
+  cFlags+=" -I$JAVA_HOME/include -I$JAVA_HOME/include/freebsd"
+  linkFlags+=" -shared"
+  libFilename="libsqliteij.so"
 elif [ "$OS" == "linux" ]; then
   libFilename="libsqliteij.so"
 
@@ -69,7 +73,7 @@ libFile="$outDir/$libFilename"
 
 libFile="$outDir/$libFilename"
 "${CROSS_PREFIX}${CC}" $cFlags -o "$libFile" "$outDir/NativeDB.o" "$outDir/sqlite3.o" $linkFlags
-shasum -a 256 "$libFile" | head -c 64 >"$libFile.sha256"
+sha256sum "$libFile" | head -c 64 >"$libFile.sha256"
 
 unlink "$outDir/sqlite3.o"
 unlink "$outDir/NativeDB.o"
