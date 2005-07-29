--- i18n/inc/collator.hxx.orig	Sat Apr  6 12:19:32 2002
+++ i18n/inc/collator.hxx	Wed May  1 22:31:57 2002
@@ -78,7 +78,7 @@
 #include <com/sun/star/lang/XServiceInfo.hpp>
 #endif
 
-#if !(defined WIN32 || defined MACOSX || defined NETBSD)
+#if !(defined WIN32 || defined MACOSX || defined NETBSD || defined FREEBSD)
 #include <alloca.h>
 #endif
 #include <tools/string.hxx>
