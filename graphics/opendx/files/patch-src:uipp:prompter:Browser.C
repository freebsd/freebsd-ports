--- src/uipp/prompter/Browser.C.orig	Tue Mar 20 18:52:42 2001
+++ src/uipp/prompter/Browser.C	Wed Mar 21 07:50:16 2001
@@ -38,7 +38,13 @@
 #define  stat  _stat
 #endif
 
-#if  defined(HAVE_RE_COMP)
+#if HAVE_REGCOMP && HAVE_REGEX_H
+extern "C" {
+#include <regex.h>
+}
+#undef HAVE_RE_COMP
+#undef HAVE_FINDFIRST
+#elif  defined(HAVE_RE_COMP)
 #undef HAVE_REGCMP
 #undef HAVE_REGCOMP
 #undef HAVE_FINDFIRST
@@ -49,7 +55,7 @@
 #undef HAVE_FINDFIRST
 extern "C" char *regcmp(...);
 extern "C" char *regex(char *, char *, ...);
-#elif HAVE_REGCOMP
+#elif HAVE_REGCOMP && HAVE_REGEXP_H
 extern "C" {
 #include <regexp.h>
 }
@@ -1476,7 +1482,12 @@
 
     theIBMApplication->setBusyCursor(TRUE);
 
-#if defined(HAVE_REGCOMP)
+#if defined(HAVE_REGCOMP) && defined(HAVE_REGEX_H)
+
+    regex_t search_for;
+    ASSERT(regcomp(&search_for, text, REG_NOSUB) == 0);
+
+#elif defined(HAVE_REGCOMP) && defined(HAVE_REGEXP_H)
 
     char *search_for = (char *)regcomp(text);
     ASSERT(search_for != NULL);
@@ -1533,7 +1544,20 @@
 
 	int offset;
 
-#if defined(HAVE_REGCOMP)
+#if defined(HAVE_REGCOMP) && defined(HAVE_REGEX_H)
+
+	int i;
+	for (i = 0; i < STRLEN(buf); i++)
+	    if (regexec(&search_for, buf + i, 0, NULL, 0) != 0)
+		break;
+	
+	if (i)
+	{
+	    offset = i - 1;
+	    found = 1;
+	}	    
+
+#elif defined(HAVE_REGCOMP) && defined(HAVE_REGEXP_H)
 
 	int i;
 	for (i = 0; i < STRLEN(buf); i++)
@@ -1610,7 +1634,7 @@
     if(!found)
 	WarningMessage("Pattern not found");
 
-#if defined(HAVE_RECOMP) || defined(HAVE_REGCMP)
+#if defined(HAVE_RE_COMP) || defined(HAVE_REGCMP)
     free(search_for);
 #endif
 
@@ -1633,7 +1657,12 @@
 
     theIBMApplication->setBusyCursor(TRUE);
 
-#if defined(HAVE_REGCOMP)
+#if defined(HAVE_REGCOMP) && defined(HAVE_REGEX_H)
+
+    regex_t search_for;
+    ASSERT(regcomp(&search_for, text, REG_NOSUB) == 0);
+    
+#elif defined(HAVE_REGCOMP) && defined(HAVE_REGEXP_H)
 
     char *search_for = (char *)regcomp(text);
     ASSERT(search_for != NULL);
@@ -1695,7 +1724,20 @@
 
 	int offset;
 
-#if defined(HAVE_REGCOMP)
+#if defined(HAVE_REGCOMP) && defined(HAVE_REGEX_H)
+
+	if (regexec(&search_for, buf, 0, NULL, 0) == 0)
+	{
+	    found = 1;
+	    
+	    for (i = STRLEN(buf)-1; i >= 0; i--)
+		if (regexec(&search_for, buf + i, 0, NULL, 0) != 0)
+		    break;
+	    
+	    offset = i + 1;
+	}
+	
+#elif defined(HAVE_REGCOMP) && defined(HAVE_REGEXP_H)
 
 	if (regexec((regexp *)search_for, buf))
 	{
