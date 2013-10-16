--- 3rdparty/map2gcm/main.cpp.orig	2013-06-17 16:27:54.000000000 +0400
+++ 3rdparty/map2gcm/main.cpp	2013-09-25 08:33:07.841519182 +0400
@@ -83,7 +83,7 @@
         if(pj) pj_free(pj);
     }
 
-    bool operator<(const file_t& other)
+    bool operator<(const file_t& other) const
     {
         return (xscale < other.xscale);
     }
