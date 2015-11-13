--- vmshf.c.orig	2006-05-10 04:36:12 UTC
+++ vmshf.c
@@ -306,14 +306,7 @@ static uint32_t LocalToUtf8(char *dst, c
 	unix systems with iconv.h
 	-- use iconv() for code conversion
 */
-#ifdef __FreeBSD__
-#include <sys/types.h>
-#include <sys/iconv.h>
-typedef size_t iconv_t;
-#else	/* __FreeBSD__ */
 #include <iconv.h>
-#endif	/* __FreeBSD__ */
-
 #include <langinfo.h>
 #include <locale.h>
 #include <strings.h>
