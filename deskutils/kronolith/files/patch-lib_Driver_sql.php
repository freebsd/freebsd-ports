--- lib/Driver/sql.php.orig	Sat May 18 00:58:16 2002
+++ lib/Driver/sql.php	Mon Dec 23 23:12:46 2002
@@ -61,7 +61,7 @@
 
             /* Connect to the SQL server using the supplied parameters. */
             $this->db = &DB::connect($this->params, true);
-            if (DB::isError($this->db) || DB::isWarning($this->db)) {
+            if (DB::isError($this->db)) {
                 Horde::fatal($this->db, __FILE__, __LINE__);
             }
 
