--- lib/Horde/Themes/Element.php.orig	2020-09-06 03:24:25 UTC
+++ lib/Horde/Themes/Element.php
@@ -143,7 +143,7 @@ class Horde_Themes_Element
         switch ($name) {
         case 'fs':
         case 'uri':
-            return $this->_data[$name];
+            return (isset($this->_data[$name])) ? $this->_data[$name] : null;
 
         case 'fulluri':
             return Horde::url($this->_data['uri'], true);
