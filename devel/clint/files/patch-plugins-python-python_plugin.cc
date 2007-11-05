--- plugins/python/python_plugin.cc.orig	Mon Apr 16 13:23:28 2001
+++ plugins/python/python_plugin.cc	Thu Nov 30 22:35:49 2006
@@ -51,11 +51,11 @@
             rules.push_back( rule );
          }
       }
+      closedir(curdir);
    } else {
       // There is something wrong with the directory. Probably doesn't
       // exist
    }
-   closedir(curdir);
    return;
 }
 
