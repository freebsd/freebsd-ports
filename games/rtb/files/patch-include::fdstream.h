--- include/fdstream.h.orig	Thu Sep 18 02:35:57 2003
+++ include/fdstream.h	Sat Mar 13 02:07:54 2004
@@ -28,9 +28,15 @@
 #ifndef BOOST_FDSTREAM_HPP
 #define BOOST_FDSTREAM_HPP
 
+#if defined __GNUC__ && __GNUC__ < 3
+#include <istream.h>
+#include <ostream.h>
+#include <streambuf.h>
+#else
 #include <istream>
 #include <ostream>
 #include <streambuf>
+#endif
 // for EOF:
 #include <cstdio>
 // for memmove():
