--- src/util/filesys.h.orig	Mon Jan 12 14:01:33 2004
+++ src/util/filesys.h	Sat Jan 17 23:40:36 2004
@@ -6,6 +6,7 @@
 #include <string>
 #include <ios>			// mode for access
 #include <stdexcept>
+#include <time.h>
 
 /// An exception to use when a libc call fails and sets errno.
 class ClibException : public std::runtime_error {
