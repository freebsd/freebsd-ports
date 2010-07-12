--- ./Graph/Layout.php.orig	2010-06-14 17:05:41.000000000 +0200
+++ ./Graph/Layout.php	2010-06-14 17:06:24.000000000 +0200
@@ -175,7 +175,7 @@
     function _push($edge, $size = '100%')
     {
         $result = array();
-        if (ereg("([0-9]*)\%", $size, $result)) {
+        if (preg_match("/([0-9]*)\%/", $size, $result)) {
             $this->_alignSize[$edge] = array(
                 'value' => min(100, max(0, $result[1])),
                 'unit' => 'percentage'
