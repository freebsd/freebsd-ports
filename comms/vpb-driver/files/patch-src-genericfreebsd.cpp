--- src/genericfreebsd.cpp	Wed Feb 19 14:19:30 2003
+++ src/genericfreebsd.cpp	Mon Oct 10 22:07:11 2005
@@ -44,6 +44,11 @@
 #include "generic.h"
 #include "vpb_ioctl.h"
 
+#define	MAX_BOARDS	12
+#define	BANKA		8
+#define	BANKB		12
+int 		vpb_pconf[MAX_BOARDS][BANKB];
+
 void GenericInitializeCriticalSection(GENERIC_CRITICAL_SECTION *cs) {
 	int                 ret;
 	pthread_mutex_t     *pmut;
@@ -219,6 +224,28 @@
 	params.data = buf;
   
 	return ioctl(fd, VPB_IOC_PCI_BLOCK_WRITE, &params);
+}
+
+int Generic_pci_block_iicread(
+			   int fd, 
+			   unsigned short board, 
+			   unsigned short addr, 
+			   unsigned short length, 
+			   unsigned short *buf)
+{
+	// not supported in FreeBSD yet
+	return -1;
+}
+
+int Generic_pci_block_iicwrite(
+			   int fd, 
+			   unsigned short board, 
+			   unsigned short addr, 
+			   unsigned short length, 
+			   unsigned short *buf)
+{
+	// not supported in FreeBSD yet
+	return -1;
 }
 
 int Generic_pci_block_eeread(
