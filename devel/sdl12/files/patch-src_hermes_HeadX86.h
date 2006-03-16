
$FreeBSD$

--- src/hermes/HeadX86.h.orig
+++ src/hermes/HeadX86.h
@@ -79,56 +79,47 @@
   extern "C" {
   #endif
 
-  int Hermes_X86_CPU() __attribute__ ((alias ("_Hermes_X86_CPU")));
+  extern int _Hermes_X86_CPU();
 
-  void ConvertX86(HermesConverterInterface *) __attribute__ ((alias ("_ConvertX86")));
+  extern void _ConvertX86(HermesConverterInterface *);
 
-#if 0
-  void ClearX86_32(HermesClearInterface *) __attribute__ ((alias ("_ClearX86_32")));
-  void ClearX86_24(HermesClearInterface *)  __attribute__ ((alias ("_ClearX86_24")));
-  void ClearX86_16(HermesClearInterface *)  __attribute__ ((alias ("_ClearX86_16")));
-  void ClearX86_8(HermesClearInterface *)  __attribute__ ((alias ("_ClearX86_8")));
-#endif
+  extern void _ConvertX86p32_32BGR888();
+  extern void _ConvertX86p32_32RGBA888();
+  extern void _ConvertX86p32_32BGRA888();
+  extern void _ConvertX86p32_24RGB888();
+  extern void _ConvertX86p32_24BGR888();
+  extern void _ConvertX86p32_16RGB565();
+  extern void _ConvertX86p32_16BGR565();
+  extern void _ConvertX86p32_16RGB555();
+  extern void _ConvertX86p32_16BGR555();
+  extern void _ConvertX86p32_8RGB332();
 
-  void ConvertX86p32_32BGR888() __attribute__ ((alias ("_ConvertX86p32_32BGR888")));
-  void ConvertX86p32_32RGBA888() __attribute__ ((alias ("_ConvertX86p32_32RGBA888")));
-  void ConvertX86p32_32BGRA888() __attribute__ ((alias ("_ConvertX86p32_32BGRA888")));
-  void ConvertX86p32_24RGB888() __attribute__ ((alias ("_ConvertX86p32_24RGB888")));
-  void ConvertX86p32_24BGR888() __attribute__ ((alias ("_ConvertX86p32_24BGR888")));
-  void ConvertX86p32_16RGB565() __attribute__ ((alias ("_ConvertX86p32_16RGB565")));
-  void ConvertX86p32_16BGR565() __attribute__ ((alias ("_ConvertX86p32_16BGR565")));
-  void ConvertX86p32_16RGB555() __attribute__ ((alias ("_ConvertX86p32_16RGB555")));
-  void ConvertX86p32_16BGR555() __attribute__ ((alias ("_ConvertX86p32_16BGR555")));
-  void ConvertX86p32_8RGB332() __attribute__ ((alias ("_ConvertX86p32_8RGB332")));
+  extern void _ConvertX86p16_16BGR565();
+  extern void _ConvertX86p16_16RGB555();
+  extern void _ConvertX86p16_16BGR555();
+  extern void _ConvertX86p16_8RGB332();
 
-#if 0
-  void ConvertX86p16_32RGB888() __attribute__ ((alias ("_ConvertX86p16_32RGB888")));
-  void ConvertX86p16_32BGR888() __attribute__ ((alias ("_ConvertX86p16_32BGR888")));
-  void ConvertX86p16_32RGBA888() __attribute__ ((alias ("_ConvertX86p16_32RGBA888")));
-  void ConvertX86p16_32BGRA888() __attribute__ ((alias ("_ConvertX86p16_32BGRA888")));
-  void ConvertX86p16_24RGB888() __attribute__ ((alias ("_ConvertX86p16_24RGB888")));
-  void ConvertX86p16_24BGR888() __attribute__ ((alias ("_ConvertX86p16_24BGR888")));
-#endif
-  void ConvertX86p16_16BGR565() __attribute__ ((alias ("_ConvertX86p16_16BGR565")));
-  void ConvertX86p16_16RGB555() __attribute__ ((alias ("_ConvertX86p16_16RGB555")));
-  void ConvertX86p16_16BGR555() __attribute__ ((alias ("_ConvertX86p16_16BGR555")));
-  void ConvertX86p16_8RGB332() __attribute__ ((alias ("_ConvertX86p16_8RGB332")));
 
-#if 0
-  void CopyX86p_4byte() __attribute__ ((alias ("_CopyX86p_4byte")));
-  void CopyX86p_3byte() __attribute__ ((alias ("_CopyX86p_3byte")));
-  void CopyX86p_2byte() __attribute__ ((alias ("_CopyX86p_2byte")));
-  void CopyX86p_1byte() __attribute__ ((alias ("_CopyX86p_1byte")));
+  #define Hermes_X86_CPU _Hermes_X86_CPU
 
-  void ConvertX86pI8_32() __attribute__ ((alias ("_ConvertX86pI8_32")));
-  void ConvertX86pI8_24() __attribute__ ((alias ("_ConvertX86pI8_24")));
-  void ConvertX86pI8_16() __attribute__ ((alias ("_ConvertX86pI8_16")));
+  #define ConvertX86 _ConvertX86
+
+  #define ConvertX86p32_32BGR888 _ConvertX86p32_32BGR888
+  #define ConvertX86p32_32RGBA888 _ConvertX86p32_32RGBA888
+  #define ConvertX86p32_32BGRA888 _ConvertX86p32_32BGRA888
+  #define ConvertX86p32_24RGB888 _ConvertX86p32_24RGB888
+  #define ConvertX86p32_24BGR888 _ConvertX86p32_24BGR888
+  #define ConvertX86p32_16RGB565 _ConvertX86p32_16RGB565
+  #define ConvertX86p32_16BGR565 _ConvertX86p32_16BGR565
+  #define ConvertX86p32_16RGB555 _ConvertX86p32_16RGB555
+  #define ConvertX86p32_16BGR555 _ConvertX86p32_16BGR555
+  #define ConvertX86p32_8RGB332 _ConvertX86p32_8RGB332
+
+  #define ConvertX86p16_16BGR565 _ConvertX86p16_16BGR565
+  #define ConvertX86p16_16RGB555 _ConvertX86p16_16RGB555
+  #define ConvertX86p16_16BGR555 _ConvertX86p16_16BGR555
+  #define ConvertX86p16_8RGB332 _ConvertX86p16_8RGB332
 
-  extern int ConvertX86p16_32RGB888_LUT_X86[512] __attribute__ ((alias ("_ConvertX86p16_32RGB888_LUT_X86")));
-  extern int ConvertX86p16_32BGR888_LUT_X86[512] __attribute__ ((alias ("_ConvertX86p16_32BGR888_LUT_X86")));
-  extern int ConvertX86p16_32RGBA888_LUT_X86[512] __attribute__ ((alias ("_ConvertX86p16_32RGBA888_LUT_X86")));
-  extern int ConvertX86p16_32BGRA888_LUT_X86[512] __attribute__ ((alias ("_ConvertX86p16_32BGRA888_LUT_X86")));
-#endif
 
   #ifdef __cplusplus
   }
