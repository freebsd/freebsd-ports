--- libs/general-writer/general-writer.cpp.orig	2023-05-11 11:57:33 UTC
+++ libs/general-writer/general-writer.cpp
@@ -39,6 +39,7 @@
 #include <string.h>
 
 #define PROGRESS_EVENT 0
+#define	UNUSED(x)	((void)(x))
 
 namespace ncbi
 {
