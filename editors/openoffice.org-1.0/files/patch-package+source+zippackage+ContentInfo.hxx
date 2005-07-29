--- package/source/zippackage/ContentInfo.hxx.orig	Tue Oct 30 14:54:47 2001
+++ package/source/zippackage/ContentInfo.hxx	Wed Jun 12 23:10:42 2002
@@ -75,7 +75,7 @@
 #endif
 #include <hash_map>
 
-class ContentInfo : public cppu::OWeakObject
+class ZipContentInfo : public cppu::OWeakObject
 {
 public:
 	com::sun::star::uno::Reference < com::sun::star::lang::XUnoTunnel > xTunnel;
@@ -85,19 +85,19 @@
 		ZipPackageFolder *pFolder;
 		ZipPackageStream *pStream;
 	};
-	ContentInfo ( ZipPackageStream * pNewStream ) 
+	ZipContentInfo ( ZipPackageStream * pNewStream ) 
 	: bFolder ( false )
 	, pStream ( pNewStream )
 	, xTunnel ( pNewStream )
 	{
 	}
-	ContentInfo ( ZipPackageFolder * pNewFolder ) 
+	ZipContentInfo ( ZipPackageFolder * pNewFolder ) 
 	: bFolder ( true )
 	, pFolder ( pNewFolder )
 	, xTunnel ( pNewFolder )
 	{
 	}
-	virtual ~ContentInfo () 
+	virtual ~ZipContentInfo () 
 	{
 		if ( bFolder )
 			pFolder->releaseUpwardRef();
