- Determine whether cc(1) is clang or gcc at compile-time.
- Don't hash -fcolor-diagnostics; make will auto use it while make -j will not.
  There's no reason to not use the cache in either of these cases if it is
  already available.
-bdrewery


--- src/ccache.c.orig	2018-03-25 13:24:05.000000000 -0700
+++ src/ccache.c	2018-06-26 11:44:03.336177000 -0700
@@ -487,6 +487,16 @@ guess_compiler(const char *path)
 	} else if (str_eq(name, "pump") || str_eq(name, "distcc-pump")) {
 		result = GUESSED_PUMP;
 	}
+#if defined(CC_IS_CLANG) || defined(CC_IS_GCC)
+	if (result == GUESSED_UNKNOWN &&
+	    (strcmp(name, "cc") == 0 || strcmp(name, "CC") == 0 ||
+	    strcmp(name, "c++") == 0))
+#if defined(CC_IS_CLANG)
+	        result = GUESSED_CLANG;
+#elif defined(CC_IS_GCC)
+	        result = GUESSED_GCC;
+#endif
+#endif
 	free(name);
 	return result;
 }
@@ -1657,6 +1667,7 @@ calculate_common_hash(struct args *args, struct mdfour
 		free(p);
 	}
 
+#if 0
 	// Possibly hash GCC_COLORS (for color diagnostics).
 	if (guessed_compiler == GUESSED_GCC) {
 		const char *gcc_colors = getenv("GCC_COLORS");
@@ -1665,6 +1676,7 @@ calculate_common_hash(struct args *args, struct mdfour
 			hash_string(hash, gcc_colors);
 		}
 	}
+#endif
 }
 
 // Update a hash sum with information specific to the direct and preprocessor
@@ -1697,6 +1709,13 @@ calculate_object_hash(struct args *args, struct mdfour
 
 		// -Wl,... doesn't affect compilation (except for clang).
 		if (str_startswith(args->argv[i], "-Wl,") && !is_clang) {
+			continue;
+		}
+
+		/* Colors do not affect compilation. */
+		if (str_startswith(args->argv[i], "-fcolor-diagnostics") ||
+		    str_eq(args->argv[i], "-fdiagnostics-color") ||
+		    str_eq(args->argv[i], "-fdiagnostics-color=always")) {
 			continue;
 		}
 
