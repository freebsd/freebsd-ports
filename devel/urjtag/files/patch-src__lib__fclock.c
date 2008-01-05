--- src/lib/fclock.c.orig	Sat Jan  5 00:50:24 2008
+++ src/lib/fclock.c	Sat Jan  5 00:51:05 2008
@@ -66,7 +66,7 @@
     }
     result = (long double)c/CLK_TCK;
 #endif
-    assert(isnormal(result));
+    /*assert(isnormal(result));*/
     assert(result > 0);
     return result;
 }
