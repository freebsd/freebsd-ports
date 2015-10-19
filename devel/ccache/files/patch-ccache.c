Determine whether cc(1) is clang or gcc at compile-time.

--- ccache.c.orig	2015-10-15 15:01:14.756621000 -0700
+++ ccache.c	2015-10-15 15:01:47.738326000 -0700
@@ -1350,6 +1350,11 @@ compiler_is_clang(struct args *args)
 {
 	char *name = basename(args->argv[0]);
 	bool is = strstr(name, "clang") != NULL;
+#ifdef CC_IS_CLANG
+	if (strcmp(name, "cc") == 0 || strcmp(name, "CC") == 0 ||
+	    strcmp(name, "c++") == 0)
+	        is = true;
+#endif
 	free(name);
 	return is;
 }
@@ -1359,6 +1364,11 @@ compiler_is_gcc(struct args *args)
 {
 	char *name = basename(args->argv[0]);
 	bool is = strstr(name, "gcc") || strstr(name, "g++");
+#ifdef CC_IS_GCC
+	if (strcmp(name, "cc") == 0 || strcmp(name, "CC") == 0 ||
+	    strcmp(name, "c++") == 0)
+	        is = true;
+#endif
 	free(name);
 	return is;
 }
