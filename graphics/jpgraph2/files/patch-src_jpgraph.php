--- src/jpgraph.php.orig	2016-02-07 15:28:23 UTC
+++ src/jpgraph.php
@@ -1286,11 +1286,11 @@ class Graph {
         while( list($key,$value) = each($_GET) ) {
             if( is_array($value) ) {
                 foreach ( $value as $k => $v ) {
-                    $urlarg .= '&amp;'.$key.'%5B'.$k.'%5D='.urlencode($v);
+                    $urlarg .= '&amp;'.urlencode($key).'%5B'.urlencode($k).'%5D='.urlencode($v);
                 }
             }
             else {
-                $urlarg .= '&amp;'.$key.'='.urlencode($value);
+                $urlarg .= '&amp;'.urlencode($key).'='.urlencode($value);
             }
         }
 
@@ -1301,11 +1301,11 @@ class Graph {
         while( list($key,$value) = each($_POST) ) {
             if( is_array($value) ) {
                 foreach ( $value as $k => $v ) {
-                    $urlarg .= '&amp;'.$key.'%5B'.$k.'%5D='.urlencode($v);
+                    $urlarg .= '&amp;'.urlencode($key).'%5B'.urlencode($k).'%5D='.urlencode($v);
                 }
             }
             else {
-                $urlarg .= '&amp;'.$key.'='.urlencode($value);
+                $urlarg .= '&amp;'.urlencode($key).'='.urlencode($value);
             }
         }
 
