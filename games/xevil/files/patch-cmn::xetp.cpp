--- cmn/xetp.cpp.orig	2000-01-19 12:54:30.000000000 +0100
+++ cmn/xetp.cpp	2007-07-31 15:51:31.000000000 +0200
@@ -29,9 +29,10 @@
 
 #include "stdafx.h"
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #if X11
-#include <strstream.h>
+#include <strstream>
 #endif
 #if WIN32
 #include <strstrea.h>
@@ -159,7 +160,7 @@
   for (n = 0; n < physicals.length(); n++) {
     PhysicalP p = (PhysicalP)physicals.get(n);
     // computing object_length twice, but who cares.
-    _send_object(out,p,turn,(TickType)tickTypes.get(n),
+    _send_object(out,p,turn,(intptr_t)tickTypes.get(n),
                  compute_object_length(p));
   }
   
