--- stty.c.orig	2015-10-16 20:44:42 UTC
+++ stty.c
@@ -29,6 +29,31 @@
 #define RFLG	4
 #define BFLG	5
 
+#ifdef __FreeBSD__
+#define BSDLY	0020000
+#define IUCLC	0001000
+#define OFILL	0000100
+#define OFDEL	0000200
+#define NLDLY	0000400
+#define BS0	0000000
+#define BS1	0020000
+#define CR0	0000000
+#define CR1	0001000
+#define CR2	0002000
+#define CR3	0003000
+#define CRDLY	0003000
+#define FF0	0000000
+#define FF1	0100000
+#define FFDLY	0100000
+#define NL0	0000000
+#define NL1	0000400
+#define TAB1	0004000
+#define TAB2	0010000
+#define VT0	0000000
+#define VT1	0040000
+#define VTDLY	0040000
+#endif
+
 extern int errno;
 
 static struct sttyset {
@@ -91,7 +116,7 @@ static struct sttyset {
 	{ "inlcr",	IFLG,	INLCR,		INLCR	},
 	{ "igncr",	IFLG,	IGNCR,		IGNCR	},
 	{ "icrnl",	IFLG,	ICRNL,		ICRNL	},
-#ifdef IUCLC	// Missing on OSX, FreeBSD
+#ifdef __FreeBSD__	// Missing on OSX, FreeBSD
 	{ "iuclc",	IFLG,	IUCLC,		IUCLC	},
 #endif
 	{ "ixon",	IFLG,	IXON,		IXON	},
