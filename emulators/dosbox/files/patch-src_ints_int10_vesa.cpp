--- src/ints/int10_vesa.cpp.orig	2018-01-28 08:20:24.891924000 -0800
+++ src/ints/int10_vesa.cpp	2018-01-28 08:20:38.015119000 -0800
@@ -39,7 +39,7 @@ static struct {
 static char string_oem[]="S3 Incorporated. Trio64";
 static char string_vendorname[]="DOSBox Development Team";
 static char string_productname[]="DOSBox - The DOS Emulator";
-static char string_productrev[]="DOSBox "VERSION;
+static char string_productrev[]="DOSBox " VERSION;
 
 #ifdef _MSC_VER
 #pragma pack (1)
