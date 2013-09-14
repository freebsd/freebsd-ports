--- src/journal_exceptions.h.orig	2012-04-23 13:46:49.000000000 +0400
+++ src/journal_exceptions.h	2013-09-13 21:33:33.010227122 +0400
@@ -22,6 +22,7 @@
 
 #include <stdint.h>
 #include <stdexcept>
+#include <string>
 
 ///
 /// Thrown for IO-errors occurring with a journal file (unable to open file
