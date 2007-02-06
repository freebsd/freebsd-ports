--- src/remove.c.orig	Sun Jun 18 18:22:03 2006
+++ src/remove.c	Tue Nov 14 09:47:46 2006
@@ -261,7 +261,18 @@
         push_leftover(&leftover,namenode);
         continue;
       }
-      if (errno != ENOTDIR) ohshite(_("cannot remove `%.250s'"),fnvb.buf);
+      if (errno != ENOTDIR) {
+        /* dpkg includes /. in the packing list.
+         * rmdir("/.") will return EINVAL. dpkg will
+         * only attempt to remove /. when uninstalling
+         * the last package on the system, which is why
+         * Debian has never run into this issue. */
+        if (errno == EINVAL && strcmp(fnvb.buf, "/.") == 0) {
+          continue;
+        } else {
+          ohshite(_("cannot remove `%.250s'"),fnvb.buf);
+        }
+      }
       debug(dbg_eachfiledetail, "removal_bulk unlinking `%s'", fnvb.buf);
       {
         /*
@@ -378,7 +389,16 @@
       push_leftover(&leftover,namenode);
       continue;
     }
-    if (errno != ENOTDIR) ohshite(_("cannot remove `%.250s'"),fnvb.buf);
+    if (errno != ENOTDIR) {
+      /* As above, packages include /. in their packing list. 
+       * Even if we are removing the last package on the system, 
+       * don't try to remove /. */
+      if (errno == EINVAL && strcmp(fnvb.buf, "/.") == 0) {
+        continue;
+      } else {
+        ohshite(_("cannot remove `%.250s'"),fnvb.buf);
+      }
+    }
 
     push_leftover(&leftover,namenode);
     continue;
