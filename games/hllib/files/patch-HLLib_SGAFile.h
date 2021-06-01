--- HLLib/SGAFile.h.orig	2021-05-29 20:58:37 UTC
+++ HLLib/SGAFile.h
@@ -163,11 +163,11 @@ namespace HLLib
 		class CSGASpecializedDirectory : public ISGADirectory
 		{
 		public:
-			typedef typename TSGAHeader SGAHeader;
-			typedef typename TSGADirectoryHeader SGADirectoryHeader;
-			typedef typename TSGASection SGASection;
-			typedef typename TSGAFolder SGAFolder;
-			typedef typename TSGAFile SGAFile;
+			typedef TSGAHeader SGAHeader;
+			typedef TSGADirectoryHeader SGADirectoryHeader;
+			typedef TSGASection SGASection;
+			typedef TSGAFolder SGAFolder;
+			typedef TSGAFile SGAFile;
 
 			CSGASpecializedDirectory(CSGAFile& File);
 
@@ -192,10 +192,10 @@ namespace HLLib
 		class CSGASpecializedDirectory<TSGAHeader, TSGADirectoryHeader, TSGASection, TSGAFolder, SGAFile4> : public ISGADirectory
 		{
 		public:
-			typedef typename TSGAHeader SGAHeader;
-			typedef typename TSGADirectoryHeader SGADirectoryHeader;
-			typedef typename TSGASection SGASection;
-			typedef typename TSGAFolder SGAFolder;
+			typedef TSGAHeader SGAHeader;
+			typedef TSGADirectoryHeader SGADirectoryHeader;
+			typedef TSGASection SGASection;
+			typedef TSGAFolder SGAFolder;
 			typedef CSGAFile::SGAFile4 SGAFile;
 
 			CSGASpecializedDirectory(CSGAFile& File);
@@ -221,10 +221,10 @@ namespace HLLib
 		class CSGASpecializedDirectory<TSGAHeader, TSGADirectoryHeader, TSGASection, TSGAFolder, SGAFile6> : public ISGADirectory
 		{
 		public:
-			typedef typename TSGAHeader SGAHeader;
-			typedef typename TSGADirectoryHeader SGADirectoryHeader;
-			typedef typename TSGASection SGASection;
-			typedef typename TSGAFolder SGAFolder;
+			typedef TSGAHeader SGAHeader;
+			typedef TSGADirectoryHeader SGADirectoryHeader;
+			typedef TSGASection SGASection;
+			typedef TSGAFolder SGAFolder;
 			typedef CSGAFile::SGAFile6 SGAFile;
 
 			CSGASpecializedDirectory(CSGAFile& File);
@@ -276,10 +276,6 @@ namespace HLLib
 		typedef CSGADirectory<SGAHeader6, SGADirectoryHeader5, SGASection5, SGAFolder5, SGAFile6> CSGADirectory6;
 		typedef CSGADirectory<SGAHeader6, SGADirectoryHeader7, SGASection5, SGAFolder5, SGAFile7> CSGADirectory7;
 
-		friend CSGADirectory4;
-		friend CSGADirectory5;
-		friend CSGADirectory6;
-		friend CSGADirectory7;
 
 	private:
 		static const char *lpAttributeNames[];
