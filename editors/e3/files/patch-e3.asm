--- e3.asm	Wed Jan  3 14:21:19 2001
+++ e3.asm.new	Wed Jan  3 14:21:47 2001
@@ -3620,8 +3620,8 @@
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
