- Determine whether cc(1) is clang or gcc at compile-time.
- Don't hash -fcolor-diagnostics; make will auto use it while make -j will not.
  There's no reason to not use the cache in either of these cases if it is
  already available.
-bdrewery

--- ccache.c.orig	2016-10-26 14:31:19.000000000 -0700
+++ ccache.c	2017-02-03 14:24:35.466505000 -0800
@@ -1468,6 +1468,11 @@ compiler_is_clang(struct args *args)
 {
 	char *name = basename(args->argv[0]);
 	bool result = strstr(name, "clang") != NULL;
+#ifdef CC_IS_CLANG
+	if (strcmp(name, "cc") == 0 || strcmp(name, "CC") == 0 ||
+	    strcmp(name, "c++") == 0)
+	        result = true;
+#endif
 	free(name);
 	return result;
 }
@@ -1477,6 +1482,11 @@ compiler_is_gcc(struct args *args)
 {
 	char *name = basename(args->argv[0]);
 	bool result = strstr(name, "gcc") || strstr(name, "g++");
+#ifdef CC_IS_GCC
+	if (strcmp(name, "cc") == 0 || strcmp(name, "CC") == 0 ||
+	    strcmp(name, "c++") == 0)
+	        result = true;
+#endif
 	free(name);
 	return result;
 }
@@ -1592,6 +1602,7 @@ calculate_common_hash(struct args *args,
 		free(p);
 	}
 
+#if 0
 	// Possibly hash GCC_COLORS (for color diagnostics).
 	if (compiler_is_gcc(args)) {
 		const char *gcc_colors = getenv("GCC_COLORS");
@@ -1600,6 +1611,7 @@ calculate_common_hash(struct args *args,
 			hash_string(hash, gcc_colors);
 		}
 	}
+#endif
 }
 
 // Update a hash sum with information specific to the direct and preprocessor
@@ -1629,6 +1641,13 @@ calculate_object_hash(struct args *args,
 			continue;
 		}
 
+		/* Colors do not affect compilation. */
+		if (str_startswith(args->argv[i], "-fcolor-diagnostics") ||
+		    str_eq(args->argv[i], "-fdiagnostics-color") ||
+		    str_eq(args->argv[i], "-fdiagnostics-color=always")) {
+			continue;
+		}
+
 		// The -fdebug-prefix-map option may be used in combination with
 		// CCACHE_BASEDIR to reuse results across different directories. Skip it
 		// from hashing.
