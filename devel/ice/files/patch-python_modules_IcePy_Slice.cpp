--- python/modules/IcePy/Slice.cpp.orig	2024-06-05 08:43:42 UTC
+++ python/modules/IcePy/Slice.cpp
@@ -20,8 +20,12 @@
 //
 // Python headers needed for PyEval_EvalCode.
 //
+#if PY_VERSION_HEX >= 0x02050000 && PY_VERSION_HEX < 0x030B0000
 #include <compile.h>
 #include <eval.h>
+#else
+#include <compile.h>
+#endif
 
 using namespace std;
 using namespace IcePy;
