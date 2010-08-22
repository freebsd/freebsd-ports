--- plugins/dfxvideo/gpu.c.orig	2010-05-20 05:55:08.652920412 +0000
+++ plugins/dfxvideo/gpu.c	2010-05-20 05:55:46.907370070 +0000
@@ -1930,3 +1930,6 @@
 }
 
 ////////////////////////////////////////////////////////////////////////
+
+/* missing symbol : do nothing */
+void CALLBACK GPUclearDynarec(void) {}
