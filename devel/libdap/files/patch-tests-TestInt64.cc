--- tests/TestInt64.cc.orig	2015-09-08 22:42:20 UTC
+++ tests/TestInt64.cc
@@ -105,7 +105,7 @@ TestInt64::read()
             d_buf = 64;
     }
     else {
-        d_buf = 0x00ffffffffffffff;
+        d_buf = 0x00ffffffffffffffLL;
     }
 
     set_read_p(true);
