--- install-mono-prefix.sh.orig	2018-06-25 19:19:03 UTC
+++ install-mono-prefix.sh
@@ -16,4 +16,4 @@ fi
 
 MONO_PREFIX=$1
 
-msbuild mono/build/install.proj /p:MonoInstallPrefix=$MONO_PREFIX /p:Configuration=$CONFIG
+msbuild mono/build/install.proj /p:DESTDIR=$DESTDIR /p:MonoInstallPrefix=$MONO_PREFIX /p:Configuration=$CONFIG
