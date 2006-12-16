--- include/odbc++/drivermanager.h.orig	Sat Dec 16 16:35:49 2006
+++ include/odbc++/drivermanager.h	Sat Dec 16 16:36:48 2006
@@ -30,6 +30,7 @@
 namespace odbc {
 
   class Connection;
+  class ErrorHandler;
   
   /** An ODBC Driver with it's information.
    */
