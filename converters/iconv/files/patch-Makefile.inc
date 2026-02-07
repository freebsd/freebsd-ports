--- Makefile.inc.orig	2000-11-27 22:11:47 UTC
+++ Makefile.inc
@@ -3,7 +3,7 @@ ICONV_BUILTIN_CHARSETS =	us-ascii utf-8 ucs-4-internal
 .endif
 
 .if defined(PREFIX)
-MANDIR =	${PREFIX}/man/man
+MANDIR =	${PREFIX}/share/man/man
 NOOBJ =
 .else
 PREFIX =	/usr
