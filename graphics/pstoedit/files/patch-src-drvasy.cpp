--- src/drvasy.cpp.orig	Sat Mar 12 22:28:38 2005
+++ src/drvasy.cpp	Tue Aug 23 00:05:16 2005
@@ -37,6 +37,7 @@
 
 #include <limits.h>				// PATH_MAX for MSVC
 #include <ctype.h>				// Need definition of ispunct()
+#include <unistd.h>
 #include <sstream>
 
 #if !(defined(unix) || defined(__unix__) || defined(_unix) || defined(__unix) || defined(__EMX__) || defined (NetBSD)  )
