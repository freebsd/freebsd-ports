--- src/SNESAPU/SPC700.Asm.orig	2008-04-17 15:36:56.859375762 -0400
+++ src/SNESAPU/SPC700.Asm	2008-04-17 15:36:56.835370755 -0400
@@ -424,7 +424,7 @@
 	Mov	[EBX+rX],AL
 
 	Mov	AL,[regSP]
-	Mov	[EBX+rSP],AL
+	Mov	[EBX+rSP_nr],AL
 
 	Mov	ECX,PSW+1
 	Mov	AL,80h
@@ -518,7 +518,7 @@
 	Mov	AL,[EBX+rX]
 	Mov	[regX],AL
 
-	Mov	AL,[EBX+rSP]
+	Mov	AL,[EBX+rSP_nr]
 	Mov	[regSP],AL
 
 	Mov	AL,[EBX+rPSW]
