
$FreeBSD$

--- src/hermes/HeadMMX.h.orig
+++ src/hermes/HeadMMX.h
@@ -50,21 +50,19 @@
   extern "C" {   
   #endif
 
-  void ConvertMMX(HermesConverterInterface *) __attribute__ ((alias ("_ConvertMMX")));
-#if 0
-  void ClearMMX_32(HermesClearInterface *) __attribute__ ((alias ("_ClearMMX_32")));
-  void ClearMMX_24(HermesClearInterface *)  __attribute__ ((alias ("_ClearMMX_24")));
-  void ClearMMX_16(HermesClearInterface *)  __attribute__ ((alias ("_ClearMMX_16")));
-  void ClearMMX_8(HermesClearInterface *)  __attribute__ ((alias ("_ClearMMX_8")));
-
-  void ConvertMMXp32_16RGB555() __attribute__ ((alias ("_ConvertMMXp32_16RGB555")));
-#endif
+  extern void _ConvertMMX(HermesConverterInterface *);
+  extern void _ConvertMMXpII32_24RGB888();
+  extern void _ConvertMMXpII32_16RGB565();
+  extern void _ConvertMMXpII32_16BGR565();
+  extern void _ConvertMMXpII32_16RGB555();
+  extern void _ConvertMMXpII32_16BGR555();
 
-  void ConvertMMXpII32_24RGB888() __attribute__ ((alias ("_ConvertMMXpII32_24RGB888")));
-  void ConvertMMXpII32_16RGB565() __attribute__ ((alias ("_ConvertMMXpII32_16RGB565")));
-  void ConvertMMXpII32_16BGR565() __attribute__ ((alias ("_ConvertMMXpII32_16BGR565")));
-  void ConvertMMXpII32_16RGB555() __attribute__ ((alias ("_ConvertMMXpII32_16RGB555")));
-  void ConvertMMXpII32_16BGR555() __attribute__ ((alias ("_ConvertMMXpII32_16BGR555")));
+  #define ConvertMMX _ConvertMMX
+  #define ConvertMMXpII32_24RGB888 _ConvertMMXpII32_24RGB888
+  #define ConvertMMXpII32_16RGB565 _ConvertMMXpII32_16RGB565
+  #define ConvertMMXpII32_16BGR565 _ConvertMMXpII32_16BGR565
+  #define ConvertMMXpII32_16RGB555 _ConvertMMXpII32_16RGB555
+  #define ConvertMMXpII32_16BGR555 _ConvertMMXpII32_16BGR555
 
   #ifdef __cplusplus
   }
