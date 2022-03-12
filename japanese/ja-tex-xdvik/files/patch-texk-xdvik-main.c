--- texk/xdvik/main.c.orig	2014-04-03 01:17:12 UTC
+++ texk/xdvik/main.c
@@ -39,6 +39,9 @@
 #include "filehist.h"
 #include "mag.h"
 #include "message-window.h"
+#ifdef HAVE_LIBPAPER
+#include <paper.h>
+#endif
 
 #if FREETYPE
 # include <ft2build.h>
@@ -54,6 +57,14 @@ static const char *xdvi_kpse_prog_name =
 #undef STRINGIFY
 #undef TOSTRING
 
+#ifdef	PTEX
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#if	HAVE_FONTCONFIG
+#include <fontconfig/fontconfig.h>
+#endif	/* HAVE_FONTCONFIG */
+#endif	/* PTEX */
+
 static char XtRBool3[] = "Bool3";	/* resource for Bool3 */
 
 /* get these before setting `application_resources' */
@@ -651,8 +662,16 @@ init_check_resources(void)
 
     /* paper type */
     if (!set_paper_type(resource.paper)) {
-	const char **p;
 	char *helpmsg = xstrdup("Possible paper types are:\n    ");
+#ifdef HAVE_LIBPAPER
+	const struct paper *pp;
+
+	for (pp = paperfirst(); pp; pp = papernext(pp)) {
+		helpmsg = xstrcat(helpmsg, papername(pp));
+		helpmsg = xstrcat(helpmsg, " ");
+	}
+#else
+	const char **p;
 	const char **paper_types = get_paper_types();
 	for (p = paper_types; p < paper_types + get_paper_types_size(); p += 2) {
 	    if (**p == '\0') { /* next line of list */
@@ -663,6 +682,7 @@ init_check_resources(void)
 		helpmsg = xstrcat(helpmsg, " ");
 	    }
 	}
+#endif
 	helpmsg = xstrcat(helpmsg,
 			  "\n(the names ending with `r' are `rotated' or `landscape' variants).\n"
 			  "Alternatively, you can specify the dimensions as `WIDTHxHEIGHT', followed "
@@ -778,6 +798,9 @@ static void
 display_version_info(void)
 {
     printf("%s version %s ", XDVIK_PROGNAME, XDVI_VERSION);
+#ifdef JPVERSION
+    printf("%s ", JPVERSION);
+#endif
 #ifdef MOTIF
     printf("(%s, runtime version %d.%d)\n",
 	   /* 	   XmVERSION, XmREVISION, XmUPDATE_LEVEL, */
@@ -786,12 +809,19 @@ display_version_info(void)
 #else
     printf("%s\n", XDVI_GUI);
 #endif
+    printf("Libraries: %s", kpathsea_version_string);
+#ifdef HAVE_LIBPAPER
+    printf(", libpaper");
+#endif
 #if FREETYPE
-    printf("Libraries: %s, freetype version %d.%d.%d\n",
-      kpathsea_version_string, FREETYPE_MAJOR, FREETYPE_MINOR, FREETYPE_PATCH);
-#else
-    printf("Libraries: %s\n", kpathsea_version_string);
+    printf(", freetype version %d.%d.%d", FREETYPE_MAJOR, FREETYPE_MINOR, FREETYPE_PATCH);
 #endif
+#ifdef PTEX
+#if HAVE_FONTCONFIG
+    printf(", fontconfig version %d.%d.%d", FC_MAJOR, FC_MINOR, FC_REVISION);
+#endif /* HAVE_FONTCONFIG */
+#endif /* !PTEX */
+    printf("\n");
 }
 
 
