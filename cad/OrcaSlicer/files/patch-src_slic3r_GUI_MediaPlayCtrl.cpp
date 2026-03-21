--- src/slic3r/GUI/MediaPlayCtrl.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/MediaPlayCtrl.cpp
@@ -13,7 +13,16 @@
 #include <boost/nowide/cstdio.hpp>
 #include <boost/nowide/utf8_codecvt.hpp>
 #undef pid_t
+#if BOOST_VERSION >= 108800
+#define BOOST_PROCESS_VERSION 1
+#include <boost/process/v1/child.hpp>
+#include <boost/process/v1/io.hpp>
+#include <boost/process/v1/pipe.hpp>
+#include <boost/process/v1/start_dir.hpp>
+#include <boost/process/v1/handles.hpp>
+#else
 #include <boost/process.hpp>
+#endif
 #ifdef __WIN32__
 #include <boost/process/windows.hpp>
 #else
