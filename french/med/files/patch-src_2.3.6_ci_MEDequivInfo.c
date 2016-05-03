--- src/2.3.6/ci/MEDequivInfo.c.orig	2014-10-09 08:12:59 UTC
+++ src/2.3.6/ci/MEDequivInfo.c
@@ -24,7 +24,7 @@
 #include <stdlib.h>
 
 int
-MEDequivInfo(int fid, char *maa, int ind, char *eq, char *des)
+MEDequivInfo(med_idt fid, char *maa, int ind, char *eq, char *des)
 {
   med_idt eqid;
   med_err ret;
