--- include/BzfString.h.orig	Sat Nov 23 15:04:54 2002
+++ include/BzfString.h	Sat Nov 23 15:05:16 2002
@@ -39,12 +39,14 @@
 
 #include "common.h"
 
-#if defined(sun) || defined(__MWERKS__)
+#if 1
 // solaris compiler doesn't like declaration of ostream
 #include "bzfio.h"
 #else
 class ostream;
 #endif
+
+using std::ostream;
 
 class BzfString {
   public:
