--- base/runtime/c-libs/posix-tty/tcgetattr.c.orig	Thu Jun  1 20:34:03 2000
+++ base/runtime/c-libs/posix-tty/tcgetattr.c	Sun Nov 19 13:36:18 2006
@@ -40,7 +40,7 @@
     
   /* allocate the vector; note that this might cause a GC */
     cc = ML_AllocString (msp, NCCS);
-    memcpy (PTR_MLtoC(void, cc), data.c_cc, NCCS);
+    memcpy (GET_SEQ_DATAPTR(void, cc), data.c_cc, NCCS);
 
     ML_AllocWrite (msp, 0, MAKE_DESC(DTAG_record, 7));
     ML_AllocWrite (msp, 1, iflag);
