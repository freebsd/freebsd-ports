--- src/pxa260/pxa260_LCD.h.orig	2020-11-11 00:36:26 UTC
+++ src/pxa260/pxa260_LCD.h
@@ -4,7 +4,7 @@
 #include "pxa260_CPU.h"
 #include "pxa260_IC.h"
 
-uint16_t* pxa260Framebuffer;
+extern uint16_t* pxa260Framebuffer;
 
 /*
 	PXA260 OS LCD controller
