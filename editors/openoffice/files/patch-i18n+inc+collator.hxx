--- ../i18n/inc/collator.hxx.orig	Tue Apr 23 23:15:36 2002
+++ ../i18n/inc/collator.hxx	Tue Apr 23 23:15:38 2002
@@ -79,8 +79,10 @@
 #endif
 
 #ifndef WIN32
-#ifndef MACOSX
+#ifndef MACOSX 
+#ifndef FREEBSD
 #include <alloca.h>
+#endif
 #endif
 #endif
 #include <tools/string.hxx>
