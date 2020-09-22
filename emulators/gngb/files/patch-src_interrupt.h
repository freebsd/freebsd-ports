--- src/interrupt.h.orig	2003-05-09 05:25:27 UTC
+++ src/interrupt.h
@@ -68,9 +68,9 @@ typedef struct {
   Uint8 *vram_pal_line[160];
 }GBLCDC;
 
-GBLCDC *gblcdc;
+extern GBLCDC *gblcdc;
 
-Uint8 vram_pal_line_temp[160][4];
+extern Uint8 vram_pal_line_temp[160][4];
 extern Uint8 vram_init_pal;
 
 #define gb_set_pal_bck(v) { \
@@ -98,7 +98,7 @@ typedef struct {
   Sint32 cycle;
 }GBTIMER;
 
-GBTIMER *gbtimer;
+extern GBTIMER *gbtimer;
 
 void gblcdc_init(void);
 void gblcdc_reset(void);
