--- src/abg-tools-utils.cc.orig	2021-03-07 00:11:55 UTC
+++ src/abg-tools-utils.cc
@@ -1713,6 +1713,16 @@ struct malloced_char_star_deleter
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
