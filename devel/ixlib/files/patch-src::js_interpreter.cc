--- src/js_interpreter.cc.orig	Fri Nov 28 12:56:09 2003
+++ src/js_interpreter.cc	Fri Nov 28 12:56:47 2003
@@ -89,8 +89,7 @@
 
 
 // javascript_exception -------------------------------------------------------
-javascript_exception::javascript_exception(TErrorCode error,code_location const &loc,char const *info,char *module = NULL,
-  TIndex line = 0)
+javascript_exception::javascript_exception(TErrorCode error,code_location const &loc,char const *info,char *module, TIndex line)
 : base_exception(error, NULL, module, line, "JS") {
   HasInfo = true;
   try {
