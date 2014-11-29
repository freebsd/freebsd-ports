Make return-free function void

--- jfbuild/src/kplib.c.orig	2014-11-13 08:27:09.882066653 +0100
+++ jfbuild/src/kplib.c	2014-11-13 08:27:25.864964483 +0100
@@ -2495,7 +2495,7 @@
 //===============================  DDS ends ==================================
 //=================== External picture interface begins ======================
 
-int kpgetdim (const char *buf, int leng, int *xsiz, int *ysiz)
+void kpgetdim (const char *buf, int leng, int *xsiz, int *ysiz)
 {
 	int *lptr;
 	const unsigned char *cptr;
