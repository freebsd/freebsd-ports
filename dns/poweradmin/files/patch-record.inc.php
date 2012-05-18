--- inc/record.inc.php.orig	2010-11-30 10:46:51.416703000 +0200
+++ inc/record.inc.php	2011-05-30 12:38:50.523768002 +0300
@@ -1276,14 +1276,15 @@
                         }
 
                         if($zone_master_add == "1" || $zone_slave_add == "1") {
+                                $domain = get_zone_name_from_id($zone_id);
                                 $now = time();
                                 $templ_records = get_zone_templ_records($zone_template);
                                 foreach ($templ_records as $r) {
                                         if ((preg_match('/in-addr.arpa/i', $zone_id) && ($r["type"] == "NS" || $r["type"] == "SOA")) || (!preg_match('/in-addr.arpa/i', $zone_id)))
                                         {
-                                                $name     = parse_template_value($r["name"], $zone_id);
+                                                $name     = parse_template_value($r["name"], $domain);
                                                 $type     = $r["type"];
-                                                $content  = parse_template_value($r["content"], $zone_id);
+                                                $content  = parse_template_value($r["content"], $domain);
                                                 $ttl      = $r["ttl"];
                                                 $prio     = intval($r["prio"]);
 
@@ -1307,7 +1308,7 @@
 
         $query = "UPDATE zones
                     SET zone_templ_id = " . $db->quote($zone_template, 'integer') . "
-                    WHERE id = " . $db->quote($zone_id, 'integer') ;
+                    WHERE domain_id = " . $db->quote($zone_id, 'integer') ;
 	$response = $db->exec($query);
 
         if (PEAR::isError($response)) {
