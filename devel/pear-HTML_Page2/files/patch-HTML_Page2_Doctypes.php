--- HTML/Page2/Doctypes.php.orig	2023-03-25 19:40:27 UTC
+++ HTML/Page2/Doctypes.php
@@ -92,9 +92,9 @@ $doctype['xhtml']['2.0'][] = '    "TBD">';
 
 // HTML 4.01 Strict
 $doctype['html']['4.01']['strict'][]
-    = '<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"';
-$doctype['html']['4.01']['strict'][]
-    = '        "http://www.w3.org/TR/html4/strict.dtd">';
+    = '<!DOCTYPE html>';
+#$doctype['html']['4.01']['strict'][]
+#    = '        "http://www.w3.org/TR/html4/strict.dtd">';
 
 // HTML 4.01 Transitional
 $doctype['html']['4.01']['transitional'][]
