--- DriverManager/SQLMoreResults.c.orig	Fri Oct 31 03:20:46 2003
+++ DriverManager/SQLMoreResults.c	Tue Jan 13 23:25:00 2004
@@ -262,7 +262,7 @@
          * We don't know for sure
          */
         statement -> hascols = 0;
-        statement -> state = STATE_S4;
+        statement -> state = STATE_S5;
 #endif
     }
     else if ( ret == SQL_STILL_EXECUTING )
