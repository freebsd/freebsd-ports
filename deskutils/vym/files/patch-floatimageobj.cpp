--- floatimageobj.cpp.orig	Tue Oct 19 18:31:12 2004
+++ floatimageobj.cpp	Sat Jan 15 12:25:08 2005
@@ -1,6 +1,6 @@
+#include <math.h>
 #include "floatimageobj.h"
 #include "branchobj.h"
-#include <math.h>
 
 
 /////////////////////////////////////////////////////////////////
@@ -67,7 +67,7 @@
 
 int FloatImageObj::z ()
 {
-	return lrint (icon->z());
+	return (long)rint (icon->z());
 }
 
 bool FloatImageObj::load (const QString &fn)
