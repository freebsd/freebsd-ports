--- misc.cpp.orig	Sun Sep 26 22:45:57 2004
+++ misc.cpp	Sun Oct 17 17:11:40 2004
@@ -5,6 +5,12 @@
 
 #include "misc.h"
 
+#if !defined(HAVE_LRINTF)
+static inline long int lrint(double x)
+{
+    return (long)(rint(x));
+}
+#endif
 
 ostream &operator<< (ostream &stream, QPoint const &p)
 { 
