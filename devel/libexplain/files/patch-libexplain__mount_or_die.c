--- libexplain/mount_or_die.c.orig
+++ libexplain/mount_or_die.c
@@ -42,7 +42,11 @@
     int             result;
 
 #ifdef HAVE_MOUNT
+#if defined(__FreeBSD__)
+    result = mount(source, target, flags, data);
+#else
     result = mount(source, target, file_systems_type, flags, data);
+#endif
 #else
     errno = ENOSYS;
     result = -1;
