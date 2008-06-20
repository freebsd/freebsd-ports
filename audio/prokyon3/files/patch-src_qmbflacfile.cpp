--- src/qmbflacfile.cpp.orig	2006-02-01 16:47:52.000000000 +0900
+++ src/qmbflacfile.cpp	2008-06-04 02:06:11.000000000 +0900
@@ -33,6 +33,12 @@
 #include <musicbrainz/mb_c.h>
 #include <FLAC++/metadata.h>
 
+#if !defined(FLAC_API_VERSION_CURRENT) || FLAC_API_VERSION_CURRENT < 8
+#define LEGACY_FLAC
+#else
+#undef LEGACY_FLAC
+#endif
+
 QMBFLACFile::QMBFLACFile()
 : QMBFile(), FLAC::Decoder::File(), offset(0), decode_error(false) {
     //we do nothing here.  we want to allow checking of return value,
@@ -57,17 +63,27 @@
     int lastslash = filename.findRev('/');
     metadata.SetFileName(filename.right(filename.length() - lastslash - 1));
 
+#ifdef LEGACY_FLAC
     //set the filename with the FLAC::Decoder::File class
     set_filename(fullfilename.latin1());
+#endif
 
     //tell the decoder to call the metadata callback on vorbis comments so we can get the metadata already stored in the file
     set_metadata_respond(FLAC__METADATA_TYPE_VORBIS_COMMENT);
 
     //Start reading the FLAC file
+#ifdef LEGACY_FLAC
     FLAC__FileDecoderState state = init();
 
     if (state != FLAC__FILE_DECODER_OK) {
         qWarning("QMBFLACFile::Extract(): error opening file: %i (%s).", state, FLAC__FileDecoderStateString[state]);
+#else
+    FLAC__StreamDecoderState state;
+    FLAC__StreamDecoderInitStatus initstate = init(fullfilename.latin1());
+
+    if (initstate != FLAC__STREAM_DECODER_INIT_STATUS_OK) {
+        qWarning("QMBFLACFile::Extract(): error opening file: %i (%s).", initstate, FLAC__StreamDecoderStateString[initstate]);
+#endif
         finish();
         return -1;
     }
@@ -75,7 +91,11 @@
     //read through all the metadata so our callback can catch it all
     if(!process_until_end_of_metadata ()) {
         state = get_state();
+#ifdef LEGACY_FLAC
         qWarning("QMBFLACFile::Extract(): error getting metadata: %i (%s).", state, FLAC__FileDecoderStateString[state]);
+#else
+        qWarning("QMBFLACFile::Extract(): error getting metadata: %i (%s).", state, FLAC__StreamDecoderStateString[state] );
+#endif
         decode_error = true;
         finish();
         return -2;
@@ -108,7 +128,11 @@
     while (!decode_error && offset < (unsigned long) bufferlen) {
         if (!process_single()) {
             state = get_state();
+#ifdef LEGACY_FLAC
             qWarning("QMBFLACFile::Extract(): error getting raw data: %i (%s).", state, FLAC__FileDecoderStateString[state]);
+#else
+            qWarning("QMBFLACFile::Extract(): error getting raw data: %i (%s).", state, FLAC__StreamDecoderStateString[state]);
+#endif
             decode_error = true;
             finish();
             return -2;
