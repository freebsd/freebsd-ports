--- src/model.h.orig	2021-02-28 23:52:22 UTC
+++ src/model.h
@@ -26,6 +26,8 @@
 #ifndef _MODEL_H_
 #define _MODEL_H_
 
+#include <sys/sysctl.h>
+
 extern "C"{
 #include <sysctlmibinfo2.h>
 }
