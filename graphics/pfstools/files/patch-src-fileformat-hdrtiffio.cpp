--- src/fileformat/hdrtiffio.cpp.orig	2011-10-27 08:39:07 UTC
+++ src/fileformat/hdrtiffio.cpp
@@ -66,7 +66,7 @@ HDRTiffReader::HDRTiffReader( const char
   }
 
   DEBUG_STR << "TIFF file \"" << filename << "\" ("
-	    << width << "x" << height << ")" << endl;
+	    << width << "x" << height << ")" << std::endl;
 
 	//--- image parameters
   if(!TIFFGetField(tif, TIFFTAG_COMPRESSION, &comp)) // compression type
@@ -81,7 +81,7 @@ HDRTiffReader::HDRTiffReader( const char
   switch(phot)
   {
     case PHOTOMETRIC_LOGLUV:
-      DEBUG_STR << "Photometric data: LogLuv" << endl;
+      DEBUG_STR << "Photometric data: LogLuv" << std::endl;
       if (comp != COMPRESSION_SGILOG && comp != COMPRESSION_SGILOG24)
       {
 	TIFFClose(tif);
@@ -96,7 +96,7 @@ HDRTiffReader::HDRTiffReader( const char
       relative_values=true;
       break;
     case PHOTOMETRIC_RGB:
-      DEBUG_STR << "Photometric data: RGB" << endl;
+      DEBUG_STR << "Photometric data: RGB" << std::endl;
      // read extra samples (# of alpha channels)
       if (TIFFGetField( tif, TIFFTAG_EXTRASAMPLES,
                         &extra_samples_per_pixel, &extra_sample_types )!=1)
@@ -121,36 +121,36 @@ HDRTiffReader::HDRTiffReader( const char
       if( bps==8 )
       {
 	TypeOfData = BYTE;
-	DEBUG_STR << "8bit per channel" << endl;
+	DEBUG_STR << "8bit per channel" << std::endl;
         strcpy(format_string,"linear 8bit RGB");
         relative_values=false; //!! TODO: verify if 8bit is always gamma corrected
       }
       else if( bps==16 )
       {
 	TypeOfData = WORD;
-	DEBUG_STR << "16bit per channel" << endl;
+	DEBUG_STR << "16bit per channel" << std::endl;
         strcpy(format_string,"linear 16bit RGB");
         relative_values=true;   //!! TODO: verify this case!!
       }
       else
       {
 	TypeOfData = FLOAT;
-	DEBUG_STR << "32bit float per channel" << endl;
+	DEBUG_STR << "32bit float per channel" << std::endl;
         strcpy(format_string,"linear 32bit float RGB");
         relative_values=true; 
       }
       break;
     case PHOTOMETRIC_MINISBLACK: // HDR video camera format (grayscale)
-      DEBUG_STR << "Photometric data: MINISBLACK (hdrv camera)" << endl;
+      DEBUG_STR << "Photometric data: MINISBLACK (hdrv camera)" << std::endl;
       if (!TIFFGetField(tif, TIFFTAG_SAMPLESPERPIXEL, &bps) || !bps==1)
       {
 	TIFFClose(tif);
 	throw pfs::Exception("TIFF: Unsupported samples per pixel for "
 			     "grayscale image");
       }
-      if (!TIFFGetField(tif, TIFFTAG_BITSPERSAMPLE, &bps) || !bps==16)
+      if (!TIFFGetField(tif, TIFFTAG_BITSPERSAMPLE, &bps) || !(bps==16))
       {
-	DEBUG_STR << "Detected bits per sample: " << bps << endl;
+	DEBUG_STR << "Detected bits per sample: " << bps << std::endl;
 	TIFFClose(tif);
 	throw pfs::Exception("TIFF: unsupported bits per sample for "
 			     "grayscale image.");
@@ -160,7 +160,7 @@ HDRTiffReader::HDRTiffReader( const char
       relative_values=true;
       break;
     default:
-      DEBUG_STR << "Unsupported photometric type: " << phot << endl;
+      DEBUG_STR << "Unsupported photometric type: " << phot << std::endl;
       TIFFClose(tif);
       strcpy(format_string,"unknown");
       relative_values=false;
@@ -184,12 +184,12 @@ void HDRTiffReader::readImage( pfs::Arra
   //--- image length
   uint32 imagelength;
   TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &imagelength);
-  DEBUG_STR << "Image length: " << imagelength << endl;
+  DEBUG_STR << "Image length: " << imagelength << std::endl;
 
   //--- image scanline size
   uint32 scanlinesize = TIFFScanlineSize(tif);
   buf.vp = _TIFFmalloc(scanlinesize);
-//    DEBUG_STR << "Scanline size: " << scanlinesize << endl;
+//    DEBUG_STR << "Scanline size: " << scanlinesize << std::endl;
 
 
   //--- read scan lines
