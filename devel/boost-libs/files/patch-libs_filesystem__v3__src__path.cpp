--- libs/filesystem/v3/src/path.cpp.orig	2011-12-15 17:38:14.000000000 +0300
+++ libs/filesystem/v3/src/path.cpp	2011-12-15 17:51:50.000000000 +0300
@@ -767,7 +767,7 @@
     // or LANG are wrong, for example), so dynamic initialization is used to ensure
     // that exceptions can be caught.
 
-    return std::locale("");
+    return std::locale();
 
 #   endif
   }
