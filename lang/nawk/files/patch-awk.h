--- awk.h.orig	2004/12/30 01:52:48	1.11
+++ awk.h	2008/06/04 14:04:42	1.12
@@ -127,6 +127,12 @@
 #define	FTOUPPER 12
 #define	FTOLOWER 13
 #define	FFLUSH	14
+#define FAND	15
+#define FFOR	16
+#define FXOR	17
+#define FCOMPL	18
+#define FLSHIFT	19
+#define FRSHIFT	20
 
 /* Node:  parse tree is made of nodes, with Cell's at bottom */
 
