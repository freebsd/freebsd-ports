--- src/third_party/boost/libs/filesystem/v3/src/path.cpp.orig	2013-05-01 19:03:02.000000000 +0200
+++ src/third_party/boost/libs/filesystem/v3/src/path.cpp	2013-05-01 19:03:46.000000000 +0200
@@ -35,7 +35,7 @@
 #ifdef BOOST_WINDOWS_API
 # include "windows_file_codecvt.hpp"
 # include <windows.h>
-#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
+#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) || defined(__FreeBSD__)
 # include <boost/filesystem/detail/utf8_codecvt_facet.hpp>
 #endif
 
@@ -766,7 +766,7 @@
     codecvt_facet(&std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t> >
       (path_locale));
 
-#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
+#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) || defined(__FreeBSD__)
 
   // "All BSD system functions expect their string parameters to be in UTF-8 encoding
   // and nothing else." See
