--- ./VBA/GBA.cpp.orig	2013-04-02 11:31:53.610879624 +0200
+++ ./VBA/GBA.cpp	2013-04-02 11:31:53.631880125 +0200
@@ -1054,12 +1054,12 @@
   {
 	  rom = (u8 *)malloc(0x200);
 	  loadedsize=0;
-	  i = (int)utilLoad(szFile,utilIsGBAImage,whereToLoad,size);
+	  i = (long)utilLoad(szFile,utilIsGBAImage,whereToLoad,size);
   }
   else
   {
 	  rom = utilLoad(szFile,utilIsGBAImage,whereToLoad,size);
-	  i = (int) rom;
+	  i = (long) rom;
   }
 
   //loadedsize = sizeof(*rom);
