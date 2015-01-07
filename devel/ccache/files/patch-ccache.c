Determine whether cc(1) is clang or gcc at compile-time.

--- ccache.c.orig	2015-01-06 18:24:47.738295980 -0600
+++ ccache.c	2015-01-06 18:25:58.685291460 -0600
@@ -1116,6 +1116,11 @@ compiler_is_clang(struct args *args)
 {
 	char* name = basename(args->argv[0]);
 	bool is = strstr(name, "clang");
+#ifdef CC_IS_CLANG
+	if (strcmp(name, "cc") == 0 || strcmp(name, "CC") == 0 ||
+	    strcmp(name, "c++") == 0)
+	        is = true;
+#endif
 	free(name);
 	return is;
 }
@@ -1125,6 +1130,11 @@ compiler_is_gcc(struct args *args)
 {
 	char* name = basename(args->argv[0]);
 	bool is = strstr(name, "gcc") || strstr(name, "g++");
+#ifdef CC_IS_GCC
+	if (strcmp(name, "cc") == 0 || strcmp(name, "CC") == 0 ||
+	    strcmp(name, "c++") == 0)
+	        is = true;
+#endif
 	free(name);
 	return is;
 }
