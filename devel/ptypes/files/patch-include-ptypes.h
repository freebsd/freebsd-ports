--- include/ptypes.h.orig	Sun Jan 28 16:02:10 2007
+++ include/ptypes.h	Sun Jan 28 16:45:21 2007
@@ -71,6 +71,7 @@
 
 ptpublic extern char* emptystr;
 
+class variant;
 
 class ptpublic string 
 {
@@ -871,6 +872,7 @@
     VAR_COMPOUND = VAR_STRING
 };
 
+class _varray;
 
 class ptpublic variant
 {
