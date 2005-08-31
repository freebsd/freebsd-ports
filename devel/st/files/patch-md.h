--- md.h.orig	Thu Aug 11 11:15:00 2005
+++ md.h	Thu Aug 11 11:33:23 2005
@@ -154,6 +154,8 @@
 #define MD_JB_SP   2
 #elif defined(__alpha__)
 #define MD_JB_SP  34
+#elif defined(__amd64__)
+#define MD_JB_SP  2
 #else
 #error Unknown CPU architecture
 #endif
