--- package/source/zippackage/ZipPackageFolder.cxx.orig	Wed Jun 12 23:09:16 2002
+++ package/source/zippackage/ZipPackageFolder.cxx	Wed Jun 12 23:10:42 2002
@@ -212,7 +212,7 @@
 	return maContents.size() > 0;
 }
 	// XNameAccess
-ContentInfo& ZipPackageFolder::doGetByName( const OUString& aName )
+ZipContentInfo& ZipPackageFolder::doGetByName( const OUString& aName )
 	throw(NoSuchElementException, WrappedTargetException, RuntimeException)
 {
 	ContentHash::iterator aIter = maContents.find ( aName );
@@ -286,7 +286,7 @@
 		  aCI++)
 	{ 
 		const OUString &rShortName = (*aCI).first;
-		const ContentInfo &rInfo = *(*aCI).second;
+		const ZipContentInfo &rInfo = *(*aCI).second;
 
 		Sequence < PropertyValue > aPropSet (2);
 		PropertyValue *pValue = aPropSet.getArray();
@@ -533,7 +533,7 @@
 		  aCI!=maContents.end();
 		  aCI++)
 	{ 
-		ContentInfo &rInfo = * (*aCI).second;
+		ZipContentInfo &rInfo = * (*aCI).second;
 		if ( rInfo.bFolder )// && ! rInfo.pFolder->HasReleased () )
 			rInfo.pFolder->releaseUpwardRef();
 		else //if ( !rInfo.bFolder && !rInfo.pStream->HasReleased() )
@@ -577,9 +577,9 @@
 		throw(IllegalArgumentException, ElementExistException, WrappedTargetException, RuntimeException)
 {
 	if ( pEntry->IsFolder() )
-		maContents[pEntry->aEntry.sName] = new ContentInfo ( static_cast < ZipPackageFolder *> ( pEntry ) );
+		maContents[pEntry->aEntry.sName] = new ZipContentInfo ( static_cast < ZipPackageFolder *> ( pEntry ) );
 	else
-		maContents[pEntry->aEntry.sName] = new ContentInfo ( static_cast < ZipPackageStream *> ( pEntry ) );
+		maContents[pEntry->aEntry.sName] = new ZipContentInfo ( static_cast < ZipPackageStream *> ( pEntry ) );
 
 	if ( bSetParent )
 		pEntry->setParent ( *this );
