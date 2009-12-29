--- displays/piqsl/piqsl.cpp.orig	2009-01-22 00:12:32.000000000 +0300
+++ displays/piqsl/piqsl.cpp	2009-11-23 05:15:05.000000000 +0300
@@ -29,6 +29,7 @@
 #define WIN32_LEAN_AND_MEAN
 #endif
 
+#include	<iostream.h>
 #include	<tiffio.h>
 #include	<string>
 #include	<list>
@@ -39,7 +40,7 @@
 #include	<boost/archive/iterators/transform_width.hpp>
 #include	<boost/archive/iterators/remove_whitespace.hpp>
 
-#include	<boost/pfto.hpp>
+#include	<boost/serialization/pfto.hpp>
 #ifndef	AQSIS_SYSTEM_WIN32
 #include	<sys/types.h>
 #include	<sys/socket.h>
