--- include/capabflag.h.orig	Sat May  4 15:31:48 2002
+++ include/capabflag.h	Sat May  4 15:32:07 2002
@@ -396,6 +396,7 @@
  * defined debugging levels
  */
 #define LOG_FATAL  0
+#define LOG_CRIT   0
 #define LOG_ERROR  1          /* report_error() and other errors that
                                  * are found */
 #define LOG_NOTICE 2
