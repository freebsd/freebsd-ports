--- inc/templates.inc.php.orig	2010-03-14 16:47:47.000000000 +0200
+++ inc/templates.inc.php	2010-03-14 16:48:00.000000000 +0200
@@ -193,7 +193,7 @@
 			while($r = $result->fetchRow()) {
 				// Call get_record_from_id for each row.
 				$ret[$retcount] = get_zone_templ_record_from_id($r["id"]);
-				$retcount;
+				$retcount++;
 			}
 			return $ret;
 		}
