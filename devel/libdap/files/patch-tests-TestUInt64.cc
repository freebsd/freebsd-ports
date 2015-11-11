--- tests/TestUInt64.cc.orig	2015-09-08 22:42:20 UTC
+++ tests/TestUInt64.cc
@@ -99,7 +99,7 @@ TestUInt64::read()
         d_buf = 64 * d_buf;
     }
     else {
-        d_buf = 0xffffffffffffffff;		// really big
+        d_buf = 0xffffffffffffffffLL;		// really big
     }
 
     set_read_p(true);
