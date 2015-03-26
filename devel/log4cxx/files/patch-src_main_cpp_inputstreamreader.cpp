$NetBSD: patch-src_main_cpp_inputstreamreader.cpp,v 1.1 2011/11/25 21:45:52 joerg Exp $

--- src/main/cpp/inputstreamreader.cpp.orig	2011-11-25 19:46:39.000000000 +0000
+++ src/main/cpp/inputstreamreader.cpp
@@ -20,6 +20,7 @@
 #include <log4cxx/helpers/exception.h>
 #include <log4cxx/helpers/pool.h>
 #include <log4cxx/helpers/bytebuffer.h>
+#include <cstring>
 
 using namespace log4cxx;
 using namespace log4cxx::helpers;
