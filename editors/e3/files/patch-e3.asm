--- e3.asm.orig	2010-05-10 01:16:47.000000000 +0900
+++ e3.asm	2010-07-12 10:01:52.000000000 +0900
@@ -5813,8 +5813,8 @@
 	dw KeyVICmdI	-_start	;33h
 	dw KeyVICmdR	-_start ;34h
 	dw KeyVICmdd	-_start ;35h
-	dw KeyHalfPgDn	-_start ;36h
-	dw KeyHalfPgUp	-_start ;37h
+	dw KeyHalfPgDn	-_start ;37h
+	dw KeyHalfPgUp	-_start ;36h
 	dw KeyVI1Char	-_start ;38h
 	dw KeyVIfsearch	-_start ;39h
 	dw KeyVIbsearch	-_start ;3Ah
