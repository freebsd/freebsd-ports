--- main.cpp.orig	2024-01-29 12:48:26 UTC
+++ main.cpp
@@ -44,7 +44,7 @@
 #include "version.h"
 
 #ifndef SHARE_PREFIX
-#define SHARE_PREFIX	"/usr"
+#define SHARE_PREFIX	"%%PREFIX%%"
 #endif
 
 
