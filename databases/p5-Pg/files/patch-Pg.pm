--- Pg.pm~	Tue Apr 20 05:25:06 2004
+++ Pg.pm	Thu Feb 10 00:17:29 2005
@@ -69,7 +69,7 @@
 
     my ($result, $status, $i, $j);
 
-    $$array_ref[0][0] = '';
+    @$array_ref = ();
 
     if ($result = $conn->exec($query)) {
         if (2 == ($status = $result->resultStatus)) {
