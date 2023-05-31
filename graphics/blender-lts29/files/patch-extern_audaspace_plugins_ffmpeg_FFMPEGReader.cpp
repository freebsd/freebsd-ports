--- extern/audaspace/plugins/ffmpeg/FFMPEGReader.cpp.orig	2023-05-12 23:31:30 UTC
+++ extern/audaspace/plugins/ffmpeg/FFMPEGReader.cpp
@@ -182,7 +182,7 @@ void FFMPEGReader::init()
 
 	// get a decoder and open it
 #ifndef FFMPEG_OLD_CODE
-	AVCodec* aCodec = avcodec_find_decoder(m_formatCtx->streams[m_stream]->codecpar->codec_id);
+	const AVCodec* aCodec = avcodec_find_decoder(m_formatCtx->streams[m_stream]->codecpar->codec_id);
 
 	if(!aCodec)
 		AUD_THROW(FileException, "File couldn't be read, no decoder found with ffmpeg.");
