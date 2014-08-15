--- unix/unxcfg.h.orig	2009-04-16 18:36:12 UTC
+++ unix/unxcfg.h
@@ -227,4 +227,30 @@ typedef struct stat z_stat;
 /* wild_dir, dirname, wildname, matchname[], dirnamelen, have_dirname, */
 /*    and notfirstcall are used by do_wild().                          */
 
+
+#define MAX_CP_NAME 25 
+   
+#ifdef SETLOCALE
+#  undef SETLOCALE
+#endif
+#define SETLOCALE(category, locale) setlocale(category, locale)
+#include <locale.h>
+   
+#ifdef _ISO_INTERN
+#  undef _ISO_INTERN
+#endif
+#define _ISO_INTERN(str1) iso_intern(str1)
+
+#ifdef _OEM_INTERN
+#  undef _OEM_INTERN
+#endif
+#ifndef IZ_OEM2ISO_ARRAY
+#  define IZ_OEM2ISO_ARRAY
+#endif
+#define _OEM_INTERN(str1) oem_intern(str1)
+
+void iso_intern(char *);
+void oem_intern(char *);
+void init_conversion_charsets(void);
+   
 #endif /* !__unxcfg_h */
