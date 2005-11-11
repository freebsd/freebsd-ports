--- includes/functions.inc.php.orig	Sun Oct 23 09:03:37 2005
+++ includes/functions.inc.php	Sun Oct 30 10:51:12 2005
@@ -18,19 +18,31 @@
    */
    function get_language_pack($lang, $module)
    {
-      $before = get_defined_vars();
+      // MC: functions module is in functions.*inc*.php
+      if ($module == 'functions') {
+          $module .= '.inc';
+      }
+
+      $before   = get_defined_vars();
       require_once("lang/en/$module.php");
       $after_en = get_defined_vars();
-      $new_var = array_keys(array_diff($after_en, $before));
-      $new_var_name = @$new_var[1];
-      $new_var['en'] = @$$new_var_name;
-      if (file_exists("lang/$lang/$module.php"))
-      {
-         require_once("lang/$lang/$module.php");
-      }
-      $new_var[$lang] = @$$new_var_name;
+      $new_var  = array_keys(array_diff($after_en, $before));
 
-      $$new_var_name = @array_merge($new_var['en'], $new_var[$lang]);
+      if (isset($new_var[1])) {
+          list(, $new_var_name) = $new_var;
+          $new_var['en'] = $$new_var_name;
+
+          if (file_exists("lang/$lang/$module.php")) {
+             require_once("lang/$lang/$module.php");
+          }
+          $new_var[$lang] = $$new_var_name;
+          // $$new_var_name  = array_merge($new_var['en'], $new_var[$lang]);
+          $$new_var_name  = $new_var['en'];
+          $merge_ref      =& $$new_var_name;
+          foreach ($new_var[$lang] as $key => $val) {
+              $merge_ref[$key] = $val;
+          }
+      }
    }
 
    /**   Redirects the browser to the page in $url
@@ -189,17 +201,19 @@
 
       $status_id = $get_details['item_status'];
 
-      require("lang/$lang/status.php");
+      global $status_list, $severity_list, $priority_list;
+      $this->get_language_pack($lang, 'status');
+      $this->get_language_pack($lang, 'severity');
+      $this->get_language_pack($lang, 'priority');
+
       $tmp_array = array("status_name" => $status_list[$status_id]);
       $get_details = $get_details + $tmp_array;
 
       $severity_id = $get_details['task_severity'];
-      require("lang/$lang/severity.php");
       $tmp_array = array("severity_name" => $severity_list[$severity_id]);
       $get_details = $get_details + $tmp_array;
 
       $priority_id = $get_details['task_priority'];
-      require("lang/$lang/priority.php");
       $tmp_array = array("priority_name" => $priority_list[$priority_id]);
       $get_details = $get_details + $tmp_array;
 
@@ -301,8 +315,9 @@
       global $db;
       global $dbprefix;
       global $lang;
+      global $functions_text;
 
-      require("lang/$lang/functions.inc.php");
+      $this->get_language_pack($lang, 'functions');
 
       // Just in case $perpage is something weird, like 0, fix it here:
       if ($perpage < 1) { $perpage = ($totalcount > 0 ? $totalcount : 1); }
