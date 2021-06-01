--- HLLib/SGAFile.cpp.orig	2021-05-29 21:01:07 UTC
+++ HLLib/SGAFile.cpp
@@ -301,37 +301,37 @@ CSGAFile::CSGADirectory<TSGAHeader, TSGADirectoryHeade
 template<typename TSGAHeader, typename TSGADirectoryHeader, typename TSGASection, typename TSGAFolder, typename TSGAFile>
 hlBool CSGAFile::CSGADirectory<TSGAHeader, TSGADirectoryHeader, TSGASection, TSGAFolder, TSGAFile>::MapDataStructures()
 {
-	if(!this->File.pMapping->Map(this->pHeaderDirectoryView, sizeof(SGAHeader), static_cast<const SGAHeader *>(this->File.pHeader)->uiHeaderLength))
+	if(!this->File.pMapping->Map(this->pHeaderDirectoryView, sizeof(TSGAHeader), static_cast<const TSGAHeader *>(this->File.pHeader)->uiHeaderLength))
 	{
 		return hlFalse;
 	}
 
-	this->pDirectoryHeader = static_cast<const SGADirectoryHeader *>(this->pHeaderDirectoryView->GetView());
+	this->pDirectoryHeader = static_cast<const TSGADirectoryHeader *>(this->pHeaderDirectoryView->GetView());
 
-	if(this->pDirectoryHeader->uiSectionCount > 0 && this->pDirectoryHeader->uiSectionOffset + sizeof(SGASection) * this->pDirectoryHeader->uiSectionCount > static_cast<const SGAHeader *>(this->File.pHeader)->uiHeaderLength)
+	if(this->pDirectoryHeader->uiSectionCount > 0 && this->pDirectoryHeader->uiSectionOffset + sizeof(TSGASection) * this->pDirectoryHeader->uiSectionCount > static_cast<const TSGAHeader *>(this->File.pHeader)->uiHeaderLength)
 	{
 		LastError.SetErrorMessage("Invalid file: the file map is too small for section data.");
 		return hlFalse;
 	}
-	if(this->pDirectoryHeader->uiFolderCount > 0 && this->pDirectoryHeader->uiFolderOffset + sizeof(SGAFolder) * this->pDirectoryHeader->uiFolderCount > static_cast<const SGAHeader *>(this->File.pHeader)->uiHeaderLength)
+	if(this->pDirectoryHeader->uiFolderCount > 0 && this->pDirectoryHeader->uiFolderOffset + sizeof(TSGAFolder) * this->pDirectoryHeader->uiFolderCount > static_cast<const TSGAHeader *>(this->File.pHeader)->uiHeaderLength)
 	{
 		LastError.SetErrorMessage("Invalid file: the file map is too small for folder data.");
 		return hlFalse;
 	}
-	if(this->pDirectoryHeader->uiFileCount > 0 && this->pDirectoryHeader->uiFileOffset + sizeof(SGAFile) * this->pDirectoryHeader->uiFileCount > static_cast<const SGAHeader *>(this->File.pHeader)->uiHeaderLength)
+	if(this->pDirectoryHeader->uiFileCount > 0 && this->pDirectoryHeader->uiFileOffset + sizeof(TSGAFile) * this->pDirectoryHeader->uiFileCount > static_cast<const TSGAHeader *>(this->File.pHeader)->uiHeaderLength)
 	{
 		LastError.SetErrorMessage("Invalid file: the file map is too small for file data.");
 		return hlFalse;
 	}
-	if(this->pDirectoryHeader->uiStringTableOffset > static_cast<const SGAHeader *>(this->File.pHeader)->uiHeaderLength)
+	if(this->pDirectoryHeader->uiStringTableOffset > static_cast<const TSGAHeader *>(this->File.pHeader)->uiHeaderLength)
 	{
 		LastError.SetErrorMessage("Invalid file: the file map is too small for string table data.");
 		return hlFalse;
 	}
 
-	this->lpSections = reinterpret_cast<const SGASection *>(reinterpret_cast<const hlByte *>(this->pDirectoryHeader) + this->pDirectoryHeader->uiSectionOffset);
-	this->lpFolders = reinterpret_cast<const SGAFolder *>(reinterpret_cast<const hlByte *>(this->pDirectoryHeader) + this->pDirectoryHeader->uiFolderOffset);
-	this->lpFiles = reinterpret_cast<const SGAFile *>(reinterpret_cast<const hlByte *>(this->pDirectoryHeader) + this->pDirectoryHeader->uiFileOffset);
+	this->lpSections = reinterpret_cast<const TSGASection *>(reinterpret_cast<const hlByte *>(this->pDirectoryHeader) + this->pDirectoryHeader->uiSectionOffset);
+	this->lpFolders = reinterpret_cast<const TSGAFolder *>(reinterpret_cast<const hlByte *>(this->pDirectoryHeader) + this->pDirectoryHeader->uiFolderOffset);
+	this->lpFiles = reinterpret_cast<const TSGAFile *>(reinterpret_cast<const hlByte *>(this->pDirectoryHeader) + this->pDirectoryHeader->uiFileOffset);
 	this->lpStringTable = reinterpret_cast<const hlChar *>(reinterpret_cast<const hlByte *>(this->pDirectoryHeader) + this->pDirectoryHeader->uiStringTableOffset);
 
 	return hlTrue;
@@ -352,7 +352,7 @@ hlVoid CSGAFile::CSGADirectory<TSGAHeader, TSGADirecto
 template<typename TSGAHeader, typename TSGADirectoryHeader, typename TSGASection, typename TSGAFolder, typename TSGAFile>
 CDirectoryFolder *CSGAFile::CSGADirectory<TSGAHeader, TSGADirectoryHeader, TSGASection, TSGAFolder, TSGAFile>::CreateRoot()
 {
-	CDirectoryFolder *pRoot = new CDirectoryFolder(&File);
+	CDirectoryFolder *pRoot = new CDirectoryFolder(&this->File);
 
 	for(hlUInt i = 0; i < this->pDirectoryHeader->uiSectionCount; i++)
 	{
@@ -558,7 +558,7 @@ hlBool CSGAFile::CSGADirectory<TSGAHeader, TSGADirecto
 			case HL_ITEM_FILE:
 			{
 				const CDirectoryFile *pFile = static_cast<const CDirectoryFile *>(pItem);
-				const SGAFile &File = this->lpFiles[pFile->GetID()];
+				const TSGAFile &File = this->lpFiles[pFile->GetID()];
 				switch(eAttribute)
 				{
 					case HL_SGA_ITEM_SECTION_ALIAS:
@@ -613,7 +613,7 @@ template<typename TSGAHeader, typename TSGADirectoryHe
 hlBool CSGAFile::CSGADirectory<TSGAHeader, TSGADirectoryHeader, TSGASection, TSGAFolder, TSGAFile>::GetFileExtractableInternal(const CDirectoryFile *pFile, hlBool &bExtractable) const
 {
 #if !USE_ZLIB
-	const SGAFile &File = this->lpFiles[pFile->GetID()];
+	const TSGAFile &File = this->lpFiles[pFile->GetID()];
 
 	bExtractable = File.uiType == 0;
 #else
@@ -831,7 +831,7 @@ hlBool CSGAFile::CSGASpecializedDirectory<TSGAHeader, 
 template<typename TSGAHeader, typename TSGADirectoryHeader, typename TSGASection, typename TSGAFolder, typename TSGAFile>
 hlBool CSGAFile::CSGADirectory<TSGAHeader, TSGADirectoryHeader, TSGASection, TSGAFolder, TSGAFile>::GetFileSizeInternal(const CDirectoryFile *pFile, hlUInt &uiSize) const
 {
-	const SGAFile &File = this->lpFiles[pFile->GetID()];
+	const TSGAFile &File = this->lpFiles[pFile->GetID()];
 
 	uiSize = File.uiSize;
 
@@ -841,7 +841,7 @@ hlBool CSGAFile::CSGADirectory<TSGAHeader, TSGADirecto
 template<typename TSGAHeader, typename TSGADirectoryHeader, typename TSGASection, typename TSGAFolder, typename TSGAFile>
 hlBool CSGAFile::CSGADirectory<TSGAHeader, TSGADirectoryHeader, TSGASection, TSGAFolder, TSGAFile>::GetFileSizeOnDiskInternal(const CDirectoryFile *pFile, hlUInt &uiSize) const
 {
-	const SGAFile &File = this->lpFiles[pFile->GetID()];
+	const TSGAFile &File = this->lpFiles[pFile->GetID()];
 
 	uiSize = File.uiSizeOnDisk;
 
@@ -851,18 +851,18 @@ hlBool CSGAFile::CSGADirectory<TSGAHeader, TSGADirecto
 template<typename TSGAHeader, typename TSGADirectoryHeader, typename TSGASection, typename TSGAFolder, typename TSGAFile>
 hlBool CSGAFile::CSGADirectory<TSGAHeader, TSGADirectoryHeader, TSGASection, TSGAFolder, TSGAFile>::CreateStreamInternal(const CDirectoryFile *pFile, Streams::IStream *&pStream) const
 {
-	const SGAFile &File = this->lpFiles[pFile->GetID()];
+	const TSGAFile &File = this->lpFiles[pFile->GetID()];
 
 	if(File.uiType == 0)
 	{
-		pStream = new Streams::CMappingStream(*this->File.pMapping, static_cast<const SGAHeader *>(this->File.pHeader)->uiFileDataOffset + File.uiOffset, File.uiSizeOnDisk);
+		pStream = new Streams::CMappingStream(*this->File.pMapping, static_cast<const TSGAHeader *>(this->File.pHeader)->uiFileDataOffset + File.uiOffset, File.uiSizeOnDisk);
 		return hlTrue;
 	}
 	else
 	{
 #if USE_ZLIB
 		Mapping::CView *pFileDataView = 0;
-		if(this->File.pMapping->Map(pFileDataView, static_cast<const SGAHeader *>(this->File.pHeader)->uiFileDataOffset + File.uiOffset, File.uiSizeOnDisk))
+		if(this->File.pMapping->Map(pFileDataView, static_cast<const TSGAHeader *>(this->File.pHeader)->uiFileDataOffset + File.uiOffset, File.uiSizeOnDisk))
 		{
 			hlBool bResult = hlFalse;
 			hlByte *lpInflateBuffer = new hlByte[File.uiSize];
@@ -905,4 +905,4 @@ hlVoid CSGAFile::CSGADirectory<TSGAHeader, TSGADirecto
 	{
 		delete []static_cast<const hlByte *>(static_cast<Streams::CMemoryStream &>(Stream).GetBuffer());
 	}
-}
\ No newline at end of file
+}
