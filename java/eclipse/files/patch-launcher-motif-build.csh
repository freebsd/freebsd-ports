--- plugins/platform-launcher/library/motif/build.csh.orig	Sun Jun 20 12:38:06 2004
+++ plugins/platform-launcher/library/motif/build.csh	Sun Jun 20 12:40:27 2004
@@ -48,6 +48,13 @@
         set defaultWS     = "motif"
         breaksw
             
+    case FreeBSD:
+        set makefile      = "make_freebsd.mak"
+        set defaultOS     = "freebsd"
+        set defaultOSArch = "x86"
+        set defaultWS     = "motif"
+        breaksw
+
     case Linux:
         set makefile      = "make_linux.mak"
         set defaultOS     = "linux"
@@ -120,11 +127,11 @@
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
