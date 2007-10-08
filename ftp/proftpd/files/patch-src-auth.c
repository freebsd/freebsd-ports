ndex: src/auth.c
===================================================================
RCS file: /cvsroot/proftp/proftpd/src/auth.c,v
retrieving revision 1.52
diff -u -r1.52 auth.c
--- src/auth.c	5 Oct 2007 17:04:13 -0000	1.52
+++ src/auth.c	8 Oct 2007 18:44:21 -0000
@@ -503,6 +503,17 @@
       return res;
     }
 
+    if (MODRET_ISERROR(mr)) {
+      res = MODRET_ERROR(mr);
+
+      if (cmd->tmp_pool) {
+        destroy_pool(cmd->tmp_pool);
+        cmd->tmp_pool = NULL;
+      }
+
+      return res;
+    }
+
     m = NULL;
   }
 
@@ -566,6 +577,17 @@
       return res;
     }
 
+    if (MODRET_ISERROR(mr)) {
+      res = MODRET_ERROR(mr);
+
+      if (cmd->tmp_pool) {
+        destroy_pool(cmd->tmp_pool);
+        cmd->tmp_pool = NULL;
+      }
+
+      return res;
+    }
+
     m = NULL;
   }
 
