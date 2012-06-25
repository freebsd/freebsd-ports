--- ../svxlink-11.05.orig/svxlink/trx/ToneDetector.h	2009-11-23 14:18:45.000000000 -0800
+++ svxlink/trx/ToneDetector.h	2012-05-28 10:27:56.000000000 -0700
@@ -37,7 +37,7 @@
 
 #include <sigc++/sigc++.h>
 #include <vector>
-
+#define exp10f(x) exp((x)*log(10))
 
 /****************************************************************************
  *
