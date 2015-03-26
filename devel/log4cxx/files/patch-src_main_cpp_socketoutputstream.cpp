$NetBSD: patch-src_main_cpp_socketoutputstream.cpp,v 1.1 2011/11/25 21:45:52 joerg Exp $

--- src/main/cpp/socketoutputstream.cpp.orig	2011-11-25 19:49:58.000000000 +0000
+++ src/main/cpp/socketoutputstream.cpp
@@ -19,6 +19,7 @@
 #include <log4cxx/helpers/socketoutputstream.h>
 #include <log4cxx/helpers/socket.h>
 #include <log4cxx/helpers/bytebuffer.h>
+#include <cstring>
 
 using namespace log4cxx;
 using namespace log4cxx::helpers;
