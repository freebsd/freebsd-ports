
$FreeBSD$

--- include/cst_sts.h
+++ include/cst_sts.h
@@ -47,9 +47,9 @@
 /* else where, this information plus the indexes in the Unit relation */
 /* allow reconstruction of the signal itself                          */
 struct cst_sts_struct {
-    const unsigned short *frame;  
-    const int size;      /* in samples */
-    const unsigned char *residual;
+    unsigned short *frame;  
+    int size;      /* in samples */
+    unsigned char *residual;
 };
 typedef struct cst_sts_struct cst_sts;
 
