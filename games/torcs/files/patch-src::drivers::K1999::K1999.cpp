--- src/drivers/K1999/K1999.cpp.orig	Sat Apr 19 11:48:14 2003
+++ src/drivers/K1999/K1999.cpp	Sun Feb 15 21:32:27 2004
@@ -14,8 +14,15 @@
 ////////////////////////////////////////////////////////////////////////////
 #include <iostream.h>
 #ifndef WIN32
+
+#if defined(__GNUC__) && __GNUC__ > 2
+#include <strstream>
+#else
 #include <strstream.h>
-#endif
+#endif // __GNUC__
+
+#endif // WIN32
+
 #include <iomanip.h>
 #include <math.h>
 #include <stdlib.h>
@@ -515,7 +522,7 @@
  OUTPUT("initTrack(" << index << ")");
  char szSettings[100];
 #ifndef WIN32
- ostrstream os(szSettings, sizeof(szSettings));
+ std::ostrstream os(szSettings, sizeof(szSettings));
  os << "drivers/K1999/" << index << "/settings.xml" << ends;
 #else
  sprintf(szSettings, "drivers/K1999/%d/settings.xml", index);
