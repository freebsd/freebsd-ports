--- bstring.h.orig	Tue Aug 19 18:15:26 2003
+++ bstring.h	Tue Aug 19 18:16:08 2003
@@ -28,6 +28,9 @@
 #include <fstream.h>
 #include "dos_comp.h"
 
+using std::ostream;
+using std::istream;
+
 //////////////////////////////////////////////////////////////////////////////
 
 class b_string
