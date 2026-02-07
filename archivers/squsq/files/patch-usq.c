--- usq.c.orig	1988-01-17 00:54:04 UTC
+++ usq.c
@@ -215,7 +215,7 @@ char *infile;
 		goto closein;
 	}
 
-#ifdef C70 | TOPS20
+#if defined(C70) || defined(TOPS20)
 	filecrc = getx16(inbuff);
 #else
 	filecrc = getw16(inbuff);
@@ -239,7 +239,7 @@ char *infile;
 	printf("%s -> %s: ", infile, outfile);
 #endif
 
-#ifdef C70 | TOPS20
+#if defined(C70) || defined(TOPS20)
 	numnodes = getx16(inbuff);
 #else
 	numnodes = getw16(inbuff);
