--- bstring.h.orig	1999-10-24 07:29:53.000000000 -0400
+++ bstring.h	2014-02-21 16:09:56.194556928 -0500
@@ -21,13 +21,15 @@
 #ifndef __BSTRING_HPP__
 #define __BSTRING_HPP__
 
-#include <alloc.h>
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
-#include <fstream.h>
+#include <fstream>
 #include "dos_comp.h"
 
+using std::istream;
+using std::ostream;
+
 //////////////////////////////////////////////////////////////////////////////
 
 class b_string
