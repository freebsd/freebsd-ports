--- src/TextFile.h.orig	Fri Mar 29 19:35:26 2002
+++ src/TextFile.h	Sun Feb 27 15:03:16 2005
@@ -10,12 +10,18 @@
 #endif
 #include <ctype.h>
 #include <fstream.h>
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <string.h>
 #if defined(HAVE_STRSTREA_H)
 #include <strstrea.h>
 #else
-#include <strstream.h>
+#include "strstream"
+
+using std::strstreambuf;
+using std::istrstream;
+using std::ostrstream;
+using std::strstream;
 #endif
 
 #include "fformat.h"  // strnicmp stuff
