--- src/modules/loaders/loader_eet.c.orig	2020-08-05 10:54:15 UTC
+++ src/modules/loaders/loader_eet.c
@@ -6,11 +6,6 @@
 
 #include "loader_common.h"
 
-#define SWAP32(x) (x) = \
-((((x) & 0x000000ff ) << 24) |\
- (((x) & 0x0000ff00 ) << 8) |\
- (((x) & 0x00ff0000 ) >> 8) |\
- (((x) & 0xff000000 ) >> 24))
 #include <Eet.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -379,11 +374,6 @@ void
 formats(ImlibLoader * l)
 {
    static const char  *const list_formats[] = { "eet" };
-   int                 i;
-
-   l->num_formats = sizeof(list_formats) / sizeof(char *);
-   l->formats = malloc(sizeof(char *) * l->num_formats);
-
-   for (i = 0; i < l->num_formats; i++)
-      l->formats[i] = strdup(list_formats[i]);
+   __imlib_LoaderSetFormats(l, list_formats,
+                            sizeof(list_formats) / sizeof(char *));
 }
