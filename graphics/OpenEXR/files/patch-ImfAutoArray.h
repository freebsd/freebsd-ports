--- IlmImf/ImfAutoArray.h.orig	2012-07-17 19:27:26.000000000 -0400
+++ IlmImf/ImfAutoArray.h	2012-11-30 21:29:19.902497168 -0500
@@ -46,6 +46,10 @@
 
 #include "OpenEXRConfig.h"
 
+#if !defined (HAVE_LARGE_STACK)
+#include <cstring>
+#endif
+
 namespace Imf {
 
 
@@ -57,7 +61,7 @@
     {
       public:
 
-	 AutoArray (): _data (new T [size]) { memset(_data, 0, size*sizeof(T)); }
+ 	 AutoArray (): _data (new T [size]) {::std::memset(_data, 0, size * sizeof(T));}
 	~AutoArray () {delete [] _data;}
 
 	operator T * ()			{return _data;}
