--- bin/mkcmd/machine.h.orig	Sun Jul 30 14:56:23 2000
+++ bin/mkcmd/machine.h	Thu Sep  5 00:58:57 2002
@@ -13,7 +13,7 @@
 #endif
 
 #if !defined(DEFDIR)
-#define DEFDIR	"/usr/local/lib/mkcmd:/usr/local/lib/mkcmd/type"
+#define DEFDIR	"/usr/local/share/mkcmd:/usr/local/share/mkcmd/type"
 #endif
 
 #if !defined(TILDEDIR)
@@ -105,7 +105,7 @@
 #endif
 
 #if !defined(NEED_MALLOC_EXTERN)
-#define NEED_MALLOC_EXTERN	(!USE_MALLOC_H && !defined(NEXT2) && !defined(IRIX) && !defined(BSDI))
+#define NEED_MALLOC_EXTERN	(!USE_MALLOC_H && !defined(NEXT2) && !defined(IRIX) && !defined(BSDI) && !defined(FREEBSD))
 #endif
 
 #if !defined(NEED_OFFSET_TYPE)
