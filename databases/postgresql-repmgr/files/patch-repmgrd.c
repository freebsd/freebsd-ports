--- repmgrd.c  2010-12-06 05:09:48.000000000 +0300
+++ repmgrd.c  2011-01-16 12:34:49.345998423 +0300
@@ -173,7 +173,12 @@
       }
 
     /* close the connection to the database and cleanup */
-    CloseConnections();
+    if (PQisBusy(primaryConn) == 1) 
+       CancelQuery(); 
+    if (myLocalConn != NULL)  
+      PQfinish(myLocalConn);
+    if (primaryConn != NULL && myLocalMode != PRIMARY_MODE)  
+      PQfinish(primaryConn);
 
     return 0;
 }
