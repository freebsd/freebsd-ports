--- scripts/newtask.php.orig	Thu Sep 29 21:43:25 2005
+++ scripts/newtask.php	Wed Oct 26 23:03:01 2005
@@ -104,7 +104,7 @@
             <select id="itemstatus" name="item_status" <?php if ($permissions['modify_all_tasks'] != "1") echo ' disabled="disabled"';?>>
             <?php
             // Get list of statuses
-            require("lang/$lang/status.php");
+            $fs->get_language_pack($lang, 'status');
             foreach($status_list as $key => $val)
             {
                if ($key == '2')
@@ -177,7 +177,7 @@
             <select id="taskseverity" class="adminlist" name="task_severity">
             <?php
             // Get list of severities
-            require("lang/$lang/severity.php");
+            $fs->get_language_pack($lang, 'severity');
             foreach($severity_list as $key => $val)
             {
                if ($key == '2')
@@ -198,7 +198,7 @@
             <select id="task_priority" name="task_priority" <?php if ($permissions['modify_all_tasks'] != "1") echo ' disabled="disabled"';?>>
             <?php
             // Get list of statuses
-            require("lang/$lang/priority.php");
+            $fs->get_language_pack($lang, 'priority');
             foreach($priority_list as $key => $val)
             {
                if ($key == '2')
