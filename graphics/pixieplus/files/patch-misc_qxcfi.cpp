--- misc/qxcfi.cpp.orig	Sat Sep 18 21:59:48 2004
+++ misc/qxcfi.cpp	Sat Sep 18 22:00:16 2004
@@ -1342,7 +1342,7 @@
 bool XCFImageFormat::loadProperty ( QDataStream& xcf_io, PropType& type,
 				    QByteArray& bytes )
 {
-  xcf_io >> (Q_UINT32)type;
+  xcf_io >> (Q_UINT32&)type;
 
   if ( xcf_io.device()->status() != IO_Ok ) {
     qDebug( "XCF: read failure on property type" );
