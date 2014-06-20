--- src/fileformat/pfsinjpeghdr.cpp.orig	2005-11-04 08:54:27.000000000 +0000
+++ src/fileformat/pfsinjpeghdr.cpp	2014-02-20 19:04:01.546588828 +0000
@@ -123,8 +123,8 @@
     case JPEG_HEADER_HDR:  // HDR image          
       jpeghdr_start_decompress(&jhinf);
       frame = pfsio.createFrame( jhinf.cinfo.output_width, jhinf.cinfo.output_height );
-      hdrscan = (JHSAMPLE *)malloc(jhinf.cinfo.output_width * jhinf.cinfo.output_height *
-        sizeof(JHSAMPLE)*3);
+      hdrscan = 
+        new JHSAMPLE[jhinf.cinfo.output_width * jhinf.cinfo.output_height * 3];
       // Important: test jhinf.output_scanline, not jhinf.cinfo
       int index ;
       index = 0;
@@ -144,7 +144,7 @@
         (Z->getRawData())[i] = hdrscan[3*i + 2];
       }       
       pfs::transformColorSpace( pfs::CS_RGB, X, Y, Z, pfs::CS_XYZ, X, Y, Z );	  
-      free((void *)hdrscan);
+      delete[] hdrscan;
       break;
     case JPEG_HEADER_OK:  // LDR image
     case JPEG_SUSPENDED:
