Obtained from:	https://github.com/pear/MDB2/commit/ee0563d1ac6ed2694c48701e24ed7c352edb6639

--- MDB2.php.orig	2012-10-29 15:41:51 UTC
+++ MDB2.php
@@ -575,7 +575,7 @@ class MDB2
                          $dummy3 = false)
     {
         $pear = new PEAR;
-        $err =& $pear->raiseError(null, $code, $mode, $options, $userinfo, 'MDB2_Error', true);
+        $err = $pear->raiseError(null, $code, $mode, $options, $userinfo, 'MDB2_Error', true);
         return $err;
     }
 
@@ -823,7 +823,8 @@ class MDB2
             $parsed['dbsyntax'] = $str;
         }
 
-        if (!count($dsn)) {
+        $dsn = trim($dsn);
+        if (!strlen($dsn)) {
             return $parsed;
         }
 
