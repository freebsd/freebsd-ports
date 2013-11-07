--- ./liboslcomp/oslcomp.cpp.orig	2013-07-12 08:31:18.000000000 +0930
+++ ./liboslcomp/oslcomp.cpp	2013-11-03 18:07:25.646119281 +1030
@@ -32,7 +32,7 @@
 #include <fstream>
 #include <cstdio>
 #include <streambuf>
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(_LIBCPP_VERSION) && !defined(USE_BOOST_WAVE)
 # include <ext/stdio_filebuf.h>
 #endif
 #include <cstdio>
@@ -268,7 +268,7 @@
     // std::cout << "cpp command:\n>" << cppcommand << "<\n";
     FILE *cpppipe = popen (cppcommand.c_str(), "r");
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(_LIBCPP_VERSION)
     __gnu_cxx::stdio_filebuf<char> fb (cpppipe, std::ios::in);
 #else
     std::filebuf fb (cpppipe);
