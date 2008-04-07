--- src/backend/CFLACSoundTranslator.cpp.orig	2005-05-01 06:39:38.000000000 +0200
+++ src/backend/CFLACSoundTranslator.cpp	2008-03-28 18:08:28.000000000 +0100
@@ -75,15 +75,15 @@ public:
 		for(unsigned t=0;t<MAX_CHANNELS;t++)
 			accessers[t]=NULL;
 
-		set_filename(filename.c_str());
+		//set_filename(filename.c_str());
 
 		set_metadata_ignore_all();
 		//set_metadata_respond(FLAC__METADATA_TYPE_VORBIS_COMMENT);
 		//set_metadata_respond(FLAC__METADATA_TYPE_CUESHEET);
 
-		State s=init();
-		if(s!=FLAC__FILE_DECODER_OK)
-			throw runtime_error(string(__func__)+" -- "+s.as_cstring());
+		FLAC__StreamDecoderInitStatus s=init(filename.c_str());
+		if(s!=FLAC__STREAM_DECODER_INIT_STATUS_OK)
+			throw runtime_error(string(__func__)+" -- "+FLAC__StreamDecoderInitStatusString[s]);
 	}
 
 	virtual ~MyFLACDecoderFile()
@@ -170,7 +170,7 @@ protected:
 
 		// update status bar and detect user cancel
 		FLAC__uint64 filePosition;
-		FLAC__file_decoder_get_decode_position(decoder_, &filePosition);
+		FLAC__stream_decoder_get_decode_position(decoder_, &filePosition);
 		return statusBar.update(filePosition) ? FLAC__STREAM_DECODER_WRITE_STATUS_ABORT : FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE;
 	}
 
@@ -215,7 +215,7 @@ private:
 bool CFLACSoundTranslator::onLoadSound(const string filename,CSound *sound) const
 {
 	MyFLACDecoderFile f(filename,sound);
-	return f.process_until_end_of_file();
+	return f.process_until_end_of_stream();
 }
 
 
@@ -258,7 +258,7 @@ bool CFLACSoundTranslator::onSaveSound(c
 
 	MyFLACEncoderFile f(saveLength);
 
-	f.set_filename(filename.c_str());
+	//f.set_filename(filename.c_str());
 
 	f.set_channels(sound->getChannelCount());
 
@@ -274,8 +274,8 @@ bool CFLACSoundTranslator::onSaveSound(c
 	//f.set_metadata(...) // ??? to do to set cues and user notes, etc
 
 
-	MyFLACEncoderFile::State s=f.init();
-	if(s==FLAC__STREAM_ENCODER_OK)
+	FLAC__StreamEncoderInitStatus s=f.init(filename.c_str());
+	if(s==FLAC__STREAM_ENCODER_INIT_STATUS_OK)
 	{
 		#define BUFFER_SIZE 65536
 		TAutoBuffer<FLAC__int32> buffers[MAX_CHANNELS];
@@ -328,7 +328,7 @@ bool CFLACSoundTranslator::onSaveSound(c
 		return true;
 	}
 	else
-		throw runtime_error(string(__func__)+" -- error creating FLAC encoder -- "+s.as_cstring());
+		throw runtime_error(string(__func__)+" -- error creating FLAC encoder -- "+FLAC__StreamEncoderInitStatusString[s]);
 
 }
 
