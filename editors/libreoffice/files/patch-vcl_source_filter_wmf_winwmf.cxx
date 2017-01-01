--- vcl/source/filter/wmf/winwmf.cxx.orig	2016-12-13 16:57:41 UTC
+++ vcl/source/filter/wmf/winwmf.cxx
@@ -1093,7 +1093,7 @@ void WMFReader::ReadRecordParams( sal_uI
                             {   // first EMF comment
                                 nEMFRecCount    = nComRecCount;
                                 nEMFSize        = nEMFTotalSize;
-                                pEMFStream = o3tl::make_unique<SvMemoryStream>( nEMFSize );
+                                pEMFStream = o3tl::make_unique<SvMemoryStream>(nEMFSize, 0);
                             }
                             else if( ( nEMFRecCount != nComRecCount ) || ( nEMFSize != nEMFTotalSize ) ) // add additional checks here
                             {
