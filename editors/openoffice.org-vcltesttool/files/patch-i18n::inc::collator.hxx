--- ../i18n/inc/collator.hxx.orig	Tue Mar 12 08:24:59 2002
+++ ../i18n/inc/collator.hxx	Tue Mar 12 08:25:55 2002
@@ -80,7 +80,9 @@
 
 #ifndef WIN32
 #ifndef MACOSX
+#ifndef FREEBSD
 #include <alloca.h>
+#endif
 #endif
 #endif
 #include <tools/string.hxx>
