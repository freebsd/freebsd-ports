--- 3rdparty/map2jnx/main.cpp.orig	2013-09-16 20:29:13.000000000 +0400
+++ 3rdparty/map2jnx/main.cpp	2013-09-25 08:16:33.022519128 +0400
@@ -121,7 +121,7 @@
         if(pj) pj_free(pj);
     }
 
-    bool operator<(const file_t& other)
+    bool operator<(const file_t& other) const
     {
         return (xscale > other.xscale);
     }
