--- interface_gtk/properties.h.orig	Thu Apr 11 02:39:58 2002
+++ interface_gtk/properties.h	Sun Dec 29 01:44:47 2002
@@ -19,8 +19,14 @@
 #define PROPERTIES_H
 
 #include "typedefs.h"
-#include <hash_map>
 #include <stdio.h>
+
+#if defined(__GNUC__) && (__GNUC__ > 2)
+#include <ext/hash_map>  
+using namespace __gnu_cxx;
+#else
+#include <hash_map>  
+#endif
 
 
 /**
