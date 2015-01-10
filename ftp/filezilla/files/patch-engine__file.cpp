--- src/engine/file.cpp.orig	2015-01-08 13:40:54.000000000 +0100
+++ src/engine/file.cpp		2015-01-08 13:41:36.000000000 +0100
@@ -1,5 +1,5 @@
 #include <filezilla.h>
-
+#include <errno.h>
 #include "file.h"
 
 CFile::CFile()
