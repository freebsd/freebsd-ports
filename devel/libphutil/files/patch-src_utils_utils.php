--- src/utils/utils.php.orig	2019-08-31 14:54:35 UTC
+++ src/utils/utils.php
@@ -1703,7 +1703,7 @@ function phutil_build_http_querystring_f
     list($key, $value) = phutil_http_parameter_pair($key, $value);
     $query[] = rawurlencode($key).'='.rawurlencode($value);
   }
-  $query = implode($query, '&');
+  $query = implode('&', $query);
 
   return $query;
 }
