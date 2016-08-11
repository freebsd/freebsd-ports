--- src/third_party/boost/libs/filesystem/v3/src/path.cpp.orig	2016-03-21 17:09:46.000000000 +0100
+++ src/third_party/boost/libs/filesystem/v3/src/path.cpp	2016-05-02 12:44:35.410331831 +0200
@@ -35,7 +35,7 @@
 #ifdef BOOST_WINDOWS_API
 # include "windows_file_codecvt.hpp"
 # include <windows.h>
-#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
+#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) || defined(__FreeBSD__)
 # include <boost/filesystem/detail/utf8_codecvt_facet.hpp>
 #endif
 
@@ -766,7 +766,7 @@ namespace
     codecvt_facet(&std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t> >
       (path_locale));
 
-#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
+#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) || defined(__FreeBSD__)
 
   // "All BSD system functions expect their string parameters to be in UTF-8 encoding
   // and nothing else." See
@@ -822,7 +822,7 @@ namespace filesystem3
   const path::codecvt_type*& path::wchar_t_codecvt_facet()
   {
 #   if defined(BOOST_POSIX_API) && \
-      !(defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__))
+      !(defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) || defined(__FreeBSD__))
       // A local static initialized by calling path::imbue ensures that std::locale(""),
       // which may throw, is called only if path_locale and condecvt_facet will actually
       // be used. Thus misconfigured environmental variables will only cause an
