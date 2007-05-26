--- ./src/Base/Documentation.cpp.orig	Sat Feb 24 11:44:54 2007
+++ ./src/Base/Documentation.cpp	Sun Apr 22 18:46:43 2007
@@ -44,6 +44,13 @@
 #		undef  _POSIX_C_SOURCE
 #	endif // (re-)defined in pyconfig.h
 #	include <Python.h>
+#	undef isspace
+#	undef isupper
+#	undef islower
+#	undef isalpha
+#	undef isalnum
+#	undef toupper
+#	undef tolower
 #	include <iostream>
 #	include <fstream>
 #	include <fcntl.h>
