--- src/include/fformat.h.orig	Fri Mar 29 19:35:26 2002
+++ src/include/fformat.h	Sun Feb 27 13:52:05 2005
@@ -13,7 +13,12 @@
 #if defined(HAVE_STRSTREA_H)
   #include <strstrea.h>
 #else
-  #include <strstream.h>
+  #include <strstream>
+
+  using std::strstreambuf;
+  using std::istrstream;
+  using std::ostrstream;
+  using std::strstream;
 #endif
 
 #if defined(HAVE_STRCASECMP)
