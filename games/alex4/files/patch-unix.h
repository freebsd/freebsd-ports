--- unix.h.orig	2016-06-14 16:25:53 UTC
+++ unix.h
@@ -0,0 +1,6 @@
+#ifdef __unix__
+
+char *get_homedir();
+int check_and_create_dir(const char *name);
+
+#endif
