--- scripts/details.php.orig	Sat Oct 22 13:41:22 2005
+++ scripts/details.php	Thu Oct 27 00:09:01 2005
@@ -91,17 +91,19 @@
          } elseif (isset($_COOKIE['flyspray_userid']))
          {
 
-                     $get_projects = $db->Query("SELECT DISTINCT p.*
-                                     FROM {$dbprefix}users_in_groups uig
-                                     LEFT JOIN {$dbprefix}groups g ON uig.group_id = g.group_id,
-                                     {$dbprefix}projects p
-                                     WHERE ((uig.user_id = ?
-                                     AND g.view_tasks = '1')
-                                     OR p.others_view = '1')
-                                     AND p.project_is_active = '1'
-                                     ORDER BY p.project_title",
-                                     array($current_user['user_id'])
-                                   );
+	   $get_projects = $db->Query("SELECT p.* FROM {$dbprefix}projects p
+                                       LEFT JOIN {$dbprefix}groups g
+                                       ON p.project_id=g.belongs_to_project
+                                       AND g.view_tasks=1
+                                       LEFT JOIN {$dbprefix}users_in_groups uig
+                                       ON uig.group_id = g.group_id
+                                       AND uig.user_id = ?
+                                       WHERE p.project_is_active='1'
+                                       AND (p.others_view
+                                       OR uig.user_id IS NOT NULL)
+                                       ORDER BY p.project_title",
+				       array($current_user['user_id'])
+				      );
 
          } else
          {
@@ -242,7 +244,7 @@
                   <select id="status" name="item_status">
                   <?php
                   // let's get a list of statuses and compare it to the saved one
-                  require("lang/$lang/status.php");
+                  $fs->get_language_pack($lang, 'status');
                   foreach($status_list as $key => $val)
                   {
                      if ($task_details['item_status'] == $key)
@@ -319,7 +321,7 @@
                   <select id="severity" name="task_severity">
                   <?php
                   // Get list of severities
-                  require("lang/$lang/severity.php");
+                  $fs->get_language_pack($lang, 'severity');
                   foreach($severity_list as $key => $val)
                   {
                      if ($task_details['task_severity'] == $key)
@@ -340,7 +342,7 @@
                   <select id="priority" name="task_priority">
                   <?php
                   // Get list of priorities
-                  require("lang/$lang/priority.php");
+                  $fs->get_language_pack($lang, 'priority');
                   foreach($priority_list as $key => $val)
                   {
                      if ($task_details['task_priority'] == $key)
