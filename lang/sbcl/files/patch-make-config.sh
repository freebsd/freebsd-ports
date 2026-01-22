--- make-config.sh.orig	2025-07-26 14:30:40 UTC
+++ make-config.sh
@@ -398,7 +398,7 @@ case $uname_arch in
     amd64) guessed_sbcl_arch=x86-64 ;;
     sparc*) guessed_sbcl_arch=sparc ;;
     sun*) guessed_sbcl_arch=sparc ;;
-    *ppc) guessed_sbcl_arch=ppc ;;
+    *powerpc|*ppc) guessed_sbcl_arch=ppc ;;
     ppc64) guessed_sbcl_arch=ppc ;;
     ppc64le) guessed_sbcl_arch=ppc64 ;; # is ok because there was never 32-bit LE
     Power*Macintosh) guessed_sbcl_arch=ppc ;;
@@ -431,6 +431,16 @@ if [ "$sbcl_os" = "netbsd" ] && [ `uname -p` = "aarch6
 # Under NetBSD, uname -m returns "evbarm" even if CPU is arm64.
 if [ "$sbcl_os" = "netbsd" ] && [ `uname -p` = "aarch64" ]; then
     guessed_sbcl_arch=arm64
+fi
+
+# Under FreeBSD, uname -m returns "powerpc" even if CPU is powerpc64.
+if [ "$sbcl_os" = "freebsd" ] && [ `uname -p` = "powerpc64" ]; then
+    guessed_sbcl_arch=ppc
+fi
+
+# Under FreeBSD, uname -m returns "powerpc" even if CPU is powerpc64le.
+if [ "$sbcl_os" = "freebsd" ] && [ `uname -p` = "powerpc64le" ]; then
+    guessed_sbcl_arch=ppc64
 fi
 
 echo //setting up CPU-architecture-dependent information
