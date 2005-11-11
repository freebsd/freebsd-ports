--- scripts/index.php.orig	Sat Oct 22 13:41:49 2005
+++ scripts/index.php	Thu Oct 27 00:09:01 2005
@@ -129,14 +129,16 @@
    // Those who aren't super users get this more restrictive query
    } elseif (isset($_COOKIE['flyspray_userid']))
    {
-       $check_projects = $db->Query("SELECT p.project_id
-                                     FROM {$dbprefix}users_in_groups uig
-                                     LEFT JOIN {$dbprefix}groups g ON uig.group_id = g.group_id,
-                                     {$dbprefix}projects p
-                                     WHERE ((uig.user_id = ?
-                                     AND g.view_tasks = '1')
-                                     OR p.others_view = '1')
-                                     AND p.project_is_active = '1'
+       $check_projects = $db->Query("SELECT p.* FROM {$dbprefix}projects p
+                                     LEFT JOIN {$dbprefix}groups g
+                                     ON p.project_id=g.belongs_to_project
+                                     AND g.view_tasks=1
+                                     LEFT JOIN {$dbprefix}users_in_groups uig
+                                     ON uig.group_id = g.group_id
+                                     AND uig.user_id = ?
+                                     WHERE p.project_is_active='1'
+                                     AND (p.others_view
+                                     OR uig.user_id IS NOT NULL)
                                      ORDER BY p.project_title",
                                      array($current_user['user_id'])
                                    );
@@ -334,7 +336,7 @@
     <select name="sev">
       <option value=""><?php echo $index_text['allseverities'];?></option>
       <?php
-      require("lang/$lang/severity.php");
+      $fs->get_language_pack($lang, 'severity');
       foreach($severity_list as $key => $val)
       {
          if (isset($_GET['sev']) && $_GET['sev'] == $key)
@@ -430,7 +432,7 @@
       <option value="all" <?php if (isset($_GET['status']) && $_GET['status'] == 'all') echo 'selected="selected"';?>><?php echo $index_text['allstatuses'];?></option>
       <option value="" <?php if ((isset($_GET['status']) && empty($_GET['status'])) OR !isset($_GET['status'])) { echo "selected=\"selected\"";}?>><?php echo $index_text['allopentasks'];?></option>
       <?php
-      require("lang/$lang/status.php");
+      $fs->get_language_pack($lang, 'status');
       foreach($status_list as $key => $val)
       {
          if (isset($_GET['status']) && $_GET['status'] == $key)
@@ -739,18 +741,18 @@
       {
          // Get the full status name
          $status_id = $task_details['item_status'];
-         require("lang/$lang/status.php");
+         $fs->get_language_pack($lang, 'status');
          $status = $status_list[$status_id];
       }
 
       // Get the full severity name
       $severity_id = $task_details['task_severity'];
-      require("lang/$lang/severity.php");
+      $fs->get_language_pack($lang, 'severity');
       $severity = $severity_list[$severity_id];
 
       // Get the full priority name
       $priority_id = $task_details['task_priority'];
-      require("lang/$lang/priority.php");
+      $fs->get_language_pack($lang, 'priority');
       $priority = $priority_list[$priority_id];
 
       // see if it's been assigned
