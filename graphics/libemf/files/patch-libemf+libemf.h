--- libemf/libemf.h.org	Tue Jan 29 13:54:27 2002
+++ libemf/libemf.h	Sat Oct  4 09:51:48 2003
@@ -21,16 +21,20 @@
 #ifndef _LIBEMF_H
 #define _LIBEMF_H 1
 
+#include <iostream>
 #include <cmath>
 #include <vector>
 #include <map>
 #include <functional>
+#include <backward/function.h>
 #include <algorithm>
 
 #include <config.h>
 #include <emf.h>
 
 #include <wine/w16.h>
+
+using namespace std;
 
 namespace EMF {
   /*!
