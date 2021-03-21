--- kBuild/env.sh.orig	2021-03-21 18:24:04 UTC
+++ kBuild/env.sh
@@ -327,12 +327,12 @@ if test -z "$KBUILD_HOST_ARCH"; then
     fi
 fi
 if test -z "$KBUILD_HOST_ARCH"; then
-    # Use uname -m or isainfo (lots of guesses here, please help clean this up...)
+    # Use uname -p or isainfo (lots of guesses here, please help clean this up...)
     if test "$KBUILD_HOST" = "solaris"; then
         KBUILD_HOST_ARCH=`isainfo | cut -f 1 -d ' '`
 
     else
-        KBUILD_HOST_ARCH=`uname -m`
+        KBUILD_HOST_ARCH=`uname -p`
     fi
     case "$KBUILD_HOST_ARCH" in
         x86_64|AMD64|amd64|k8|k8l|k9|k10)
