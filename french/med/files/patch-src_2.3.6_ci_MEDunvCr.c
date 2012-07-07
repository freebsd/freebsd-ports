--- ./src/2.3.6/ci/MEDunvCr.c.orig	2011-10-20 19:12:46.000000000 +0200
+++ ./src/2.3.6/ci/MEDunvCr.c	2011-12-26 19:32:03.000000000 +0100
@@ -55,6 +55,12 @@
 
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <unistd.h>
+#include <pwd.h>
+#endif
+
 med_err 
 MEDunvCr(med_idt fid, char *maa)
 {
