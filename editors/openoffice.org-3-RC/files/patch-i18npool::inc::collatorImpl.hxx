--- ../i18npool/inc/collatorImpl.hxx.orig	Fri Oct 18 19:35:02 2002
+++ ../i18npool/inc/collatorImpl.hxx	Fri Oct 18 19:35:26 2002
@@ -71,7 +71,7 @@
 #include <cppuhelper/implbase2.hxx>
 #include <com/sun/star/lang/XServiceInfo.hpp>
 
-#if !defined( WIN32 ) && !defined( MACOSX )
+#if !defined( WIN32 ) && !defined( MACOSX ) && !defined( FREEBSD)
 #include <alloca.h>
 #endif
 #include <tools/list.hxx>
