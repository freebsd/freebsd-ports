--- vpbreg.cpp.orig	Sun Dec 28 11:07:43 2003
+++ vpbreg.cpp	Sun Dec 28 11:08:25 2003
@@ -57,7 +57,7 @@
 
 #define	NUM_CARDS		1                  // number of VPBs in PC
 #define BASE                    0x300              // ISA card base address
-#define FIRMWARE_FILE	        "/etc/vpbmain.out"	
+#define FIRMWARE_FILE	        "PREFIX/etc/vpbmain.out"	
 
 /*-------------------------------------------------------------------------*\
 
