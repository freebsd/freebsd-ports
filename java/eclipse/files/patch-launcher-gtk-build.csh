--- plugins/platform-launcher/library/gtk/build.csh.orig	Sun Jun 13 22:33:13 2004
+++ plugins/platform-launcher/library/gtk/build.csh	Sun Jun 13 22:33:39 2004
@@ -72,11 +72,11 @@
 # If the OS is supported (a makefile exists)
 if ("$makefile" != "") then
     if ("$extraArgs" != "") then
-        make -f $makefile $extraArgs
+        gmake -f $makefile $extraArgs
     else
         echo "Building $OS launcher. Defaults: -os $DEFAULT_OS -arch $DEFAULT_OS_ARCH -ws $DEFAULT_WS"
-        make -f $makefile clean
-        make -f $makefile all
+        gmake -f $makefile clean
+        gmake -f $makefile all
     endif
 else
     echo "Unknown OS ($OS) -- build aborted"
