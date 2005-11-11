--- index.php.orig	Sat Oct 22 13:40:26 2005
+++ index.php	Thu Oct 27 00:09:01 2005
@@ -384,15 +384,17 @@
       // or, if the user is logged in
       } elseif (isset($_COOKIE['flyspray_userid']))
       {
-         $get_projects = $db->Query("SELECT DISTINCT p.*
-                                     FROM {$dbprefix}users_in_groups uig
-                                     LEFT JOIN {$dbprefix}groups g ON uig.group_id = g.group_id,
-                                     {$dbprefix}projects p
-                                     WHERE ((uig.user_id = ?
-                                     AND g.view_tasks = '1')
-                                     OR p.others_view = '1')
-                                     AND p.project_is_active = '1'
-                                     GROUP BY p.project_id",
+         $get_projects = $db->Query("SELECT p.* FROM {$dbprefix}projects p
+                                     LEFT JOIN {$dbprefix}groups g
+				     ON p.project_id=g.belongs_to_project
+				     AND g.view_tasks=1
+                                     LEFT JOIN {$dbprefix}users_in_groups uig
+				     ON uig.group_id = g.group_id 
+				     AND uig.user_id = ?
+                                     WHERE p.project_is_active='1'
+				     AND (p.others_view 
+				     OR uig.user_id IS NOT NULL)
+				     ORDER BY p.project_title",
                                      array($current_user['user_id'])
                                    );
       // Anonymous users
