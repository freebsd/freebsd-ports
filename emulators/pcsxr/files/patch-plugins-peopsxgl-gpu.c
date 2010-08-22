--- plugins/peopsxgl/gpu.c.orig	2010-05-20 05:59:22.148962228 +0000
+++ plugins/peopsxgl/gpu.c	2010-05-20 06:12:07.650815396 +0000
@@ -3194,3 +3194,7 @@
 {
  dwCoreFlags=dwFlags;
 }
+
+/* missing symbols : do nothing */
+void CALLBACK GPUclearDynarec(void) {}
+void CALLBACK GPUdisplayText(char * pText) {}
