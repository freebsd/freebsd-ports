Make return-free function void

--- jfbuild/src/kplib.c.orig	2020-09-03 06:19:21 UTC
+++ jfbuild/src/kplib.c
@@ -2495,7 +2495,7 @@ static int kddsrend (const char *buf, int leng,
 //===============================  DDS ends ==================================
 //=================== External picture interface begins ======================
 
-int kpgetdim (const char *buf, int leng, int *xsiz, int *ysiz)
+void kpgetdim (const char *buf, int leng, int *xsiz, int *ysiz)
 {
 	int *lptr;
 	const unsigned char *cptr;
