--- ipelib/ipeplatform.cpp.orig	2015-02-23 13:02:13 UTC
+++ ipelib/ipeplatform.cpp
@@ -37,7 +37,6 @@
 #include <direct.h>
 #else
 #include <sys/wait.h>
-#include <xlocale.h>
 #endif
 #include <cstdlib>
 #include <sys/types.h>
@@ -46,6 +45,17 @@
 #include <unistd.h>
 #include <clocale>
 
+#ifdef __FreeBSD__
+#include <osreldate.h>
+# if __FreeBSD_version < 900045
+#  define NO_XLOCALE
+# endif
+#endif
+
+#ifndef NO_XLOCALE
+#include <xlocale.h>
+#endif
+
 using namespace ipe;
 
 // --------------------------------------------------------------------
@@ -70,12 +80,14 @@ int Platform::libVersion()
 static bool initialized = false;
 static bool showDebug = false;
 static Platform::DebugHandler debugHandler = 0;
+#ifndef NO_XLOCALE
 #ifdef WIN32
 // not yet available in MINGW RT library
 // _locale_t ipeLocale;
 #else
 locale_t ipeLocale;
 #endif
+#endif
 
 #ifdef WIN32
 // Counterpart to Platform::wideToUtf8
@@ -100,11 +112,13 @@ static void debugHandlerImpl(const char 
 
 static void cleanup_repository()
 {
+#ifndef NO_XLOCALE
 #ifdef WIN32
   // _free_locale(ipeLocale);
 #else
   freelocale(ipeLocale);
 #endif
+#endif
   Repository::cleanup();
 }
 
@@ -127,11 +141,13 @@ void Platform::initLib(int version)
   if (getenv("IPEDEBUG") != 0)
     showDebug = true;
   debugHandler = debugHandlerImpl;
+#ifndef NO_XLOCALE
 #ifdef WIN32
   // ipeLocale = ::_create_locale(LC_NUMERIC, "C");
 #else
   ipeLocale = newlocale(LC_NUMERIC_MASK, "C", NULL);
 #endif
+#endif
   atexit(cleanup_repository);
 #ifndef WIN32
   if (version == IPELIB_VERSION)
@@ -462,12 +478,16 @@ String Platform::wideToUtf8(const wchar_
 
 double Platform::toDouble(String s)
 {
+#ifdef NO_XLOCALE
+  return strtod(s.z(), 0);
+#else
 #ifdef WIN32
   return strtod(s.z(), 0);
   // return _strtod_l(s.z(), 0, ipeLocale);
 #else
   return strtod_l(s.z(), 0, ipeLocale);
 #endif
+#endif
 }
 
 void ipeAssertionFailed(const char *file, int line, const char *assertion)
