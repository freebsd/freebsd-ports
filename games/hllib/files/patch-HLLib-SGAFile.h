--- ../orig/HLLib/SGAFile.h	2012-09-17 20:16:38.000000000 -0300
+++ ./HLLib/SGAFile.h	2013-02-11 17:56:51.311213431 -0200
@@ -160,8 +160,6 @@
 		typedef CSGADirectory<SGADirectoryHeader4, SGASection4, SGAFolder4, SGAFile, SGAFileHeader> CSGADirectory4;
 		typedef CSGADirectory<SGADirectoryHeader5, SGASection5, SGAFolder5, SGAFile, SGAFileHeader> CSGADirectory5;
 
-		friend CSGADirectory4;
-		friend CSGADirectory5;
 
 	private:
 		static const char *lpAttributeNames[];
Only in ./HLLib: SGAFile.h.bak
Only in ./HLLib: SGAFile.h.orig
diff -ru ../orig/HLLib/VBSPFile.cpp ./HLLib/VBSPFile.cpp
