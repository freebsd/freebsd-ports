--- usq.c.orig	Sun Jan 17 01:54:04 1988
+++ usq.c	Sun Jan 17 01:54:05 1988
@@ -215,7 +215,7 @@
 		goto closein;
 	}
 
-#ifdef C70 | TOPS20
+#if defined(C70) || defined(TOPS20)
 	filecrc = getx16(inbuff);
 #else
 	filecrc = getw16(inbuff);
@@ -239,7 +239,7 @@
 	printf("%s -> %s: ", infile, outfile);
 #endif
 
-#ifdef C70 | TOPS20
+#if defined(C70) || defined(TOPS20)
 	numnodes = getx16(inbuff);
 #else
 	numnodes = getw16(inbuff);
