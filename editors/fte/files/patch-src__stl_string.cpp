--- src/stl_string.cpp.orig	2010-03-05 20:40:08 UTC
+++ src/stl_string.cpp
@@ -10,6 +10,13 @@
 #include <stdlib.h>
 #include <string.h>
 
+#ifdef tolower
+#undef tolower
+#endif
+#ifdef toupper
+#undef toupper
+#endif
+
 FTE_BEGIN_NAMESPACE;
 
 /*
