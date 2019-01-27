Fix compiler error (missing include)

--- es-app/src/FileFilterIndex.h.orig	2018-08-11 01:19:16 UTC
+++ es-app/src/FileFilterIndex.h
@@ -4,6 +4,7 @@
 
 #include <map>
 #include <vector>
+#include <string>
 
 class FileData;
 
