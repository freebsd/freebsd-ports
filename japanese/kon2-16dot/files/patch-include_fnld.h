--- include/fnld.h.orig	1997-01-24 16:04:58.000000000 +0900
+++ include/fnld.h	2012-05-10 00:14:28.746555141 +0900
@@ -51,6 +51,10 @@
 #define	FR_ATTACH	1
 #define	FR_PROXY	2
 
+#if defined(__FreeBSD__)
+#define	ftok(p, n) (5000 + ((n) & 0x7F))
+#endif
+
 extern struct fontRegs fSRegs[], fDRegs[];
 extern struct fontRegs *sbFReg, *dbFReg;
 
