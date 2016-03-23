- Determine whether cc(1) is clang or gcc at compile-time.
- Don't hash -fcolor-diagnostics; make will auto use it while make -j will not.
  There's no reason to not use the cache in either of these cases if it is
  already available.
-bdrewery

--- ccache.c.orig	2015-10-08 19:14:23 UTC
+++ ccache.c
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
@@ -1463,6 +1473,7 @@ calculate_common_hash(struct args *args,
 		free(p);
 	}
 
+#if 0
 	/* Possibly hash GCC_COLORS (for color diagnostics). */
 	if (compiler_is_gcc(args)) {
 		const char *gcc_colors = getenv("GCC_COLORS");
@@ -1471,6 +1482,7 @@ calculate_common_hash(struct args *args,
 			hash_string(hash, gcc_colors);
 		}
 	}
+#endif
 }
 
 /*
@@ -1509,6 +1521,13 @@ calculate_object_hash(struct args *args,
 			continue;
 		}
 
+		/* Colors do not affect compilation. */
+		if (str_startswith(args->argv[i], "-fcolor-diagnostics") ||
+		    str_eq(args->argv[i], "-fdiagnostics-color") ||
+		    str_eq(args->argv[i], "-fdiagnostics-color=always")) {
+			continue;
+		}
+
 		/* The -fdebug-prefix-map option may be used in combination with
 		 * CCACHE_BASEDIR to reuse results across different directories. Skip it
 		 * from hashing. */
