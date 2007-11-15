--- Patch.c.orig	2007-11-16 02:31:51.000000000 +0600
+++ Patch.c	2007-11-16 02:35:41.000000000 +0600
@@ -24,15 +24,6 @@
 
 void SSlot(byte Value); /* Used to switch secondary slots */
 
-#ifdef FMSX
-extern byte *RAM[],PSL[],SSLReg;
-static byte RdZ80(word A)
-{
-  if(A!=0xFFFF) return(RAM[A>>13][A&0x1FFF]);
-  else return((PSL[3]==3)? ~SSLReg:RAM[7][0x1FFF]);
-}
-#endif
-
 /** PatchZ80() ***********************************************/
 /** Emulate BIOS calls. This function is called on an ED FE **/
 /** instruction to emulate disk/tape access, etc.           **/
