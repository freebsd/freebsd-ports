--- libemf/libemf.h.orig	Tue Jan 29 13:54:27 2002
+++ libemf/libemf.h	Fri Oct 24 17:04:27 2003
@@ -21,16 +21,22 @@
 #ifndef _LIBEMF_H
 #define _LIBEMF_H 1
 
+#include <iostream>
 #include <cmath>
 #include <vector>
 #include <map>
 #include <functional>
+#if __GNUC__ > 2
+#include <backward/function.h>
+#endif
 #include <algorithm>
 
 #include <config.h>
 #include <emf.h>
 
 #include <wine/w16.h>
+
+using namespace std;
 
 namespace EMF {
   /*!
