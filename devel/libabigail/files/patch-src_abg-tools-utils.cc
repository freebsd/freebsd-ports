--- src/abg-tools-utils.cc.orig	2025-06-10 09:13:49 UTC
+++ src/abg-tools-utils.cc
@@ -2143,6 +2143,16 @@ struct malloced_char_star_deleter
   {free(ptr);}
 };
 
+#ifdef __FreeBSD__
+/* get_current_dir_name() is a GNU extension.
+ *
+ */
+char *get_current_dir_name()
+{
+return getcwd(nullptr, 0);
+}
+#endif
+
 /// Return a copy of the path given in argument, turning it into an
 /// absolute path by prefixing it with the concatenation of the result
 /// of get_current_dir_name() and the '/' character.
