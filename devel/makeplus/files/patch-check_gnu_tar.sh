--- check_gnu_tar.sh.orig	Fri Feb 28 03:42:54 2003
+++ check_gnu_tar.sh	Mon Jun 14 22:59:38 2004
@@ -19,7 +19,7 @@
 # on Solaris yet.
 
 tar --help > mp-check_gnu_tar 2>&1
-if head -1 mp-check_gnu_tar | grep -q GNU >/dev/null 2>&1; then
+if head -1 mp-check_gnu_tar | grep -qe '\(GNU\|bsdtar\)' >/dev/null 2>&1; then
     echo 'HAVE_GNU_TAR := 1' >> config.mk
     echo '#define HAVE_GNU_TAR 1' >> config.h
 else
