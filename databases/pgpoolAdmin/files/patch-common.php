--- common.php.orig	Thu Apr 12 20:13:37 2007
+++ common.php	Thu Apr 12 20:13:55 2007
@@ -233,7 +233,7 @@
     if($backendHostName != '') {
         $conStr = "dbname=$healthCheckDb user=$healthCheckUser host=$backendHostName port=$backendPort" ;
     } else {
-        $conStr = "dbname=$healthCheckDb port=$backendPort" ;
+        $conStr = "dbname=$healthCheckDb user=$healthCheckUser port=$backendPort" ;
     }
 
     $conn = @pg_connect($conStr);
