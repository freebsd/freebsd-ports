--- codecs/bmp.cc.orig	2009-04-27 13:54:29.000000000 -0400
+++ codecs/bmp.cc	2010-01-17 00:32:01.000000000 -0500
@@ -441,6 +441,8 @@
       uint8_t* row_data = (uint8_t*) malloc (file_stride);
       if (!data || !row_data) {
 	std::cerr << "Can't allocate space for image buffer\n";
+	free(data);
+	free(row_data);
 	goto bad1;
       }
       
@@ -522,6 +524,7 @@
       comprbuf = (uint8_t *) malloc( compr_size );
       if (!comprbuf) {
 	std::cerr << "Can't allocate space for compressed scanline buffer\n";
+	free(comprbuf);
 	goto bad1;
       }
       uncomprbuf = (uint8_t *) malloc( uncompr_size );
@@ -593,6 +596,7 @@
       data = (uint8_t *) malloc( uncompr_size );
       if (!data) {
 	std::cerr << "Can't allocate space for final uncompressed scanline buffer\n";
+	free(data);
 	goto bad1;
       }
