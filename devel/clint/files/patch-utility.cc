--- src/utility.cc.orig	Mon Apr 16 13:19:36 2001
+++ src/utility.cc	Thu Nov 30 22:31:32 2006
@@ -40,6 +40,7 @@
                filelist.push_back(filename);
             }
          }
+         closedir(curdir);
       } else {
          // There is something wrong with the directory. Probably
          // doesn't exist
@@ -47,7 +48,6 @@
          // directory
          // throw std::invalid_argument("get_plugin_list: something is wrong with the directory " + directory);
       }
-      closedir(curdir);
       return;
    }
 
