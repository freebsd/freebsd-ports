--- src/vpbreg.cpp	Sat Feb 12 09:50:04 2005
+++ src/vpbreg.cpp	Sat Feb 12 09:50:59 2005
@@ -94,9 +94,9 @@
 
 // path and name of firmware file
 
-#define	FIRMWARE_FILE_ISA	"/etc/vpb/vpbmain_isa.out"	
-#define	FIRMWARE_FILE_ISA_VPB8L	"/etc/vpb/vlcmain.out"	
-#define	FIRMWARE_FILE_PCI	"/etc/vpb/vpbmain_pci.out"	
+#define	FIRMWARE_FILE_ISA	"%%PREFIX%%/etc/vpb/vpbmain_isa.out"	
+#define	FIRMWARE_FILE_ISA_VPB8L	"%%PREFIX%%/etc/vpb/vlcmain.out"	
+#define	FIRMWARE_FILE_PCI	"%%PREFIX%%/etc/vpb/vpbmain_pci.out"	
 
 /*-------------------------------------------------------------------------*\
 
