--- ext/etc/etc.c.orig	Tue Feb 13 02:01:19 2007
+++ ext/etc/etc.c	Fri Mar 16 14:53:15 2007
@@ -337,7 +337,7 @@
     struct group *grp;
 
     rb_secure(4);
-    gid = getgid();
+    gid = PW_VAL2GID(id);
     grp = getgrgid(gid);
     if (grp == 0) rb_raise(rb_eArgError, "can't find group for %d", gid);
     return setup_group(grp);
