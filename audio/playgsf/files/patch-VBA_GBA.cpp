--- VBA/GBA.cpp.orig	2016-07-26 15:40:39 UTC
+++ VBA/GBA.cpp
@@ -1054,12 +1054,12 @@ int CPULoadRom(const char *szFile)
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
