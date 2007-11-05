--- lib/python/python.cc.orig	2007-11-03 16:32:34.000000000 +0100
+++ lib/python/python.cc	2007-11-03 16:33:48.000000000 +0100
@@ -115,6 +115,8 @@
       } else { 
          return import_module(modname);
       }
+
+      return (NULL);
    }
 
    // }}}
