--- src/uipp/dxui/MacroDefinition.C.orig	Tue Mar 20 18:52:41 2001
+++ src/uipp/dxui/MacroDefinition.C	Tue Mar 20 20:49:26 2001
@@ -42,7 +42,14 @@
 
 #define OLD_DUMMY_DESCRIPTION_STRING "Generated dummy input"
 
-#if  defined(HAVE_RE_COMP)
+#if HAVE_REGCOMP && HAVE_REGEX_H
+/* prefer POSIX style regcomp(3) over obsolete versions */
+extern "C" {
+#include <regex.h>
+}
+#undef HAVE_RE_COMP
+#undef HAVE_FINDFIRST
+#elif  defined(HAVE_RE_COMP)
 #undef HAVE_REGCMP
 #undef HAVE_REGCOMP
 #undef HAVE_FINDFIRST
@@ -53,7 +60,7 @@
 #undef HAVE_FINDFIRST
 extern "C" char *regcmp(...);
 extern "C" char *regex(char *, char *, ...);
-#elif HAVE_REGCOMP
+#elif HAVE_REGCOMP && HAVE_REGEXP_H
 extern "C" {
 #include <regexp.h>
 }
@@ -594,7 +601,18 @@
 	}
 	else
 	{
-#if defined(HAVE_REGCOMP)
+#if defined(HAVE_REGCOMP) && defined(HAVE_REGEX_H)
+
+	    regex_t net_file;
+	    ASSERT(regcomp(&net_file, ".[.]*\\.net$", REG_NOSUB) == 0);
+
+	    struct dirent *entry;
+	    while (entry = readdir(d))
+	    {
+	        boolean exists = regexec(&net_file, entry->d_name, 0, NULL, 0);
+		if (exists == 0)
+
+#elif defined(HAVE_REGCOMP) && defined(HAVE_REGEXP_H)
 
 	    char *net_file = (char *)regcomp(".[.]*\\.net$");
 	    ASSERT(net_file != NULL);
@@ -691,7 +709,10 @@
 	    }
             _findclose(handle);
 	    delete srch_string;
-#elif defined(HAVE_REGCOMP)
+#elif defined(HAVE_REGCOMP) && defined(HAVE_REGEX_H)
+		}
+	    }
+#elif defined(HAVE_REGCOMP) && defined(HAVE_REGEXP_H)
 		}
 	    }
 #elif defined(HAVE_RE_COMP)
