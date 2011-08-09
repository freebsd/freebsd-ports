--- src/e_main.cc.orig	2008-08-23 18:00:36.000000000 +0900
+++ src/e_main.cc	2009-04-14 04:42:02.000000000 +0900
@@ -936,6 +936,8 @@
 
         if (s && epi::FS_IsDir(s))
             iwad_dir = std::string(s);
+        else
+            iwad_dir = std::string("%%DMDIR%%");
     }
 
     // Should the IWAD directory not be set by now, then we
