--- src/phpsh.php.orig
+++ src/phpsh.php
@@ -10,7 +10,7 @@
 // usage: this is only called from phpsh (the python end), as:
 // phpsh.php <comm-file> <codebase-mode> [-c]
 //
-// use '' for default codebase-mode, define others in /etc/phpsh/rc.php
+// use '' for default codebase-mode, define others in %%ETCDIR%%/rc.php
 // -c turns off color
 
 // set the TFBENV to script
@@ -46,7 +46,7 @@
 if (file_exists($___phpsh___homerc)) {
   require_once $___phpsh___homerc;
 } else {
-  require_once '/etc/phpsh/rc.php';
+  require_once '%%ETCDIR%%/rc.php';
 }
 
 $___phpsh___do_color = true;
@@ -547,7 +547,7 @@
           $err_msg =
             'Not executing input: Possible call to undefined function '.
             $undefd_func."()\n".
-            'See /etc/phpsh/config.sample to disable UndefinedFunctionCheck.';
+            'See %%ETCDIR%%/config.sample to disable UndefinedFunctionCheck.';
         }
       }
       if ($err_msg) {
