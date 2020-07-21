--- lv2lint.c.orig	2020-07-21 01:36:43 UTC
+++ lv2lint.c
@@ -668,7 +668,11 @@ _pattern_match(const char *pattern, const char *str)
 	}
 
 #if defined(HAS_FNMATCH)
+#if defined(FNM_EXTMATCH) // a GNU extension not available on FreeBSD
 	if(fnmatch(pattern, str, FNM_CASEFOLD | FNM_EXTMATCH) == 0)
+#else
+	if(fnmatch(pattern, str, FNM_CASEFOLD) == 0)
+#endif
 #else
 	if(strcasecmp(pattern, str) == 0)
 #endif
