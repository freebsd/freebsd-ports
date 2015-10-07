--- create_build_files4.sh.orig	2013-08-02 21:08:28 UTC
+++ create_build_files4.sh
@@ -4,7 +4,7 @@
 shared=""
 arch=""
 wxroot=""
-wxpath=`wx-config --prefix`
+wxpath=`%%WX_CONFIG%% --prefix`
 
 # These works only on wxWidgets 2.8.10+
 #wxcharset=`wx-config --query-chartype`
@@ -63,7 +63,7 @@ done
 
 # Autodetect wxWidgets version
 if [ "$wxroot" = "" ]; then
-    wxver=`wx-config --release`
+    wxver=`%%WX_CONFIG%% --release`
 else
     wxpath=${wxroot#-*=}
     wxver=`$wxpath/wx-config --release`
@@ -72,9 +72,9 @@ fi
 wxversion="--wx-version="$wxver
 
 # Autodetect OS
+unamestr=`uname`
 isbsd=`expr "$unamestr" : '.*BSD'`
 platform="unknown"
-unamestr=$(uname)
 
 if ( [ "$isbsd" -gt "0" ] ); then
     platform="bsd"
@@ -86,12 +86,12 @@ fi
 
 # Build premake
 cd build
-make CONFIG=Release -C./premake/$platform
+gmake CONFIG=Release -C./premake/$platform
 
-./premake/$platform/bin/release/premake4 --file=./premake/solution.lua $wxunicode $wxroot $wxversion $mediactrl $shared $arch codeblocks
-./premake/$platform/bin/release/premake4 --file=./premake/solution.lua $wxunicode $wxroot $wxversion $mediactrl $shared $arch $rpath codelite
+#./premake/$platform/bin/release/premake4 --file=./premake/solution.lua $wxunicode $wxroot $wxversion $mediactrl $shared $arch codeblocks
+#./premake/$platform/bin/release/premake4 --file=./premake/solution.lua $wxunicode $wxroot $wxversion $mediactrl $shared $arch $rpath codelite
 ./premake/$platform/bin/release/premake4 --file=./premake/solution.lua $wxunicode $wxroot $wxversion $mediactrl $shared $arch $rpath gmake
-if [ "$platform" = "macosx" ]; then
-   ./premake/$platform/bin/release/premake4 --file=./premake/solution.lua $wxunicode $wxroot $wxversion $mediactrl $shared $arch xcode3
-fi
+#if [ "$platform" = "macosx" ]; then
+#   ./premake/$platform/bin/release/premake4 --file=./premake/solution.lua $wxunicode $wxroot $wxversion $mediactrl $shared $arch xcode3
+#fi
 
