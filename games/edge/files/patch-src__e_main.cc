--- ./src/e_main.cc.orig	Thu Jun 21 00:04:22 2007
+++ ./src/e_main.cc	Wed Dec  5 23:35:20 2007
@@ -1110,6 +1110,8 @@
 
         if (s && epi::the_filesystem->IsDir(s))
             iwad_dir.Set(s);
+        else
+            iwad_dir.Set("%%DMDIR%%");
     }
 
     // Should the IWAD directory not be set by now, then we
