--- vfile-module.c.orig	Tue Aug 24 00:08:56 1999
+++ vfile-module.c	Sat Jan  6 21:53:38 2001
@@ -54,6 +54,9 @@
 #include <sys/wait.h>
 
 #include <slang.h>
+#ifdef KANJI
+#include <slkanji.h>
+#endif
 
 /* we need stripped-down version of SLang_Object_Type for cookies: */
 typedef	struct {
@@ -1331,6 +1334,9 @@
 	unsigned long ip;
 	void *data;
 	char *s = NULL;
+#ifdef KANJI
+	char *s2 = NULL;
+#endif
 	SLang_BString_Type *bs = NULL;
 	SLang_Array_Type *at = NULL;
 	SLang_MMT_Type *mmt = NULL;
@@ -1351,8 +1357,15 @@
 		case SLANG_STRING_TYPE:
 				if (SLang_pop_slstring(&s)) return -1;
 				type = strlen(s);
+#ifdef KANJI
+	                        s2 = kSLCodeConv(s,&type,kSLcode,JIS,0);
+				type = strlen(s2);
+ 				if (len < 0 || len > type) len = type;
+				data = s2;
+#else
 				if (len < 0 || len > type) len = type;
 				data = s;
+#endif
 				break;
 		case SLANG_BSTRING_TYPE:
 				if (SLang_pop_bstring(&bs)) return -1;
@@ -1397,6 +1410,11 @@
 	if (at) SLang_free_array (at);
 	if (bs) SLbstring_free(bs);
 	SLang_free_slstring(s); /* NULL is ok */
+#ifdef KANJI
+	if(s2 != NULL)
+		SLfree(s2);
+#endif
+
 	if (mmt) SLang_free_mmt(mmt);
 	return ct;
 }
