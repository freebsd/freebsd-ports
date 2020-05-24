--- printing/backend/print_backend_cups.h.orig	2019-04-08 08:18:26 UTC
+++ printing/backend/print_backend_cups.h
@@ -5,6 +5,8 @@
 #ifndef PRINTING_BACKEND_PRINT_BACKEND_CUPS_H_
 #define PRINTING_BACKEND_PRINT_BACKEND_CUPS_H_
 
+#include <cups/ppd.h>
+
 #include <string>
 
 #include "base/files/file_util.h"
