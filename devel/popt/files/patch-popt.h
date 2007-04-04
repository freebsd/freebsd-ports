--- ./popt.h.orig	Wed Apr  4 12:24:48 2007
+++ ./popt.h	Wed Apr  4 12:25:14 2007
@@ -440,7 +440,7 @@
  * @return		error string
  */
 /*@-redecl@*/
-/*@observer@*/ const char *const poptStrerror(const int error)
+/*@observer@*/ const char * poptStrerror(const int error)
 	/*@*/;
 /*@=redecl@*/
 
