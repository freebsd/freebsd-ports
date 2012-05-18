--- inc/templates.inc.php.orig	2010-12-10 23:26:28.839400000 +0200
+++ inc/templates.inc.php	2011-05-30 12:39:13.319768001 +0300
@@ -312,7 +312,7 @@
 
 // Add a zone template from zone / another template.
 
-function add_zone_templ_save_as($template_name, $description, $userid, $records) {
+function add_zone_templ_save_as($template_name, $description, $userid, $records, $domain = null) {
 	global $db;
 
 	if (!(verify_permission('zone_master_add'))) {
@@ -339,9 +339,12 @@
                             $content = $db->quote($record['content'], 'text');
                     }
 
+                    $name = $domain ? preg_replace('/'.$domain.'/', '[ZONE]',$record['name']) : $record['name'];
+                    $content = $domain ? preg_replace('/'.$domain.'/', '[ZONE]',$content) : $content;
+
                     $query2 = "INSERT INTO zone_templ_records (zone_templ_id, name, type, content, ttl, prio) VALUES ("
                                             . $db->quote($zone_templ_id, 'integer') . ","
-                                            . $db->quote($record['name'], 'text') . ","
+                                            . $db->quote($name, 'text') . ","
                                             . $db->quote($record['type'], 'text') . ","
                                             . $content . ","
                                             . $db->quote($record['ttl'], 'integer') . ","
