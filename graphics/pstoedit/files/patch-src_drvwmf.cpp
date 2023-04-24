--- src/drvwmf.cpp.orig	2021-04-17 18:52:47 UTC
+++ src/drvwmf.cpp
@@ -30,6 +30,12 @@
 #include I_stdlib
 
 #include <math.h>
+#ifdef max
+#undef max
+#endif
+#ifdef min
+#undef min
+#endif
 #include <algorithm>
 
 #ifndef M_PI
