--- classes/database/Postgres81.php.orig	Tue Feb  6 14:00:38 2007
+++ classes/database/Postgres81.php	Tue Feb  6 14:01:02 2007
@@ -83,7 +83,7 @@ class Postgres81 extends Postgres80 {
 		if (isset($conf['owned_only']) && $conf['owned_only'] && !$this->isSuperUser($server_info['username'])) {
 			$username = $server_info['username'];
 			$this->clean($username);
-			$clause = " AND pu.usename='{$username}'";
+			$clause = " AND pr.rolname='{$username}'";
 		}
 		else $clause = '';
 
