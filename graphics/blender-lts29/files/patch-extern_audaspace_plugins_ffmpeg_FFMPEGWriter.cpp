--- extern/audaspace/plugins/ffmpeg/FFMPEGWriter.cpp.orig	2023-05-12 23:31:30 UTC
+++ extern/audaspace/plugins/ffmpeg/FFMPEGWriter.cpp
@@ -23,6 +23,7 @@ extern "C" {
 extern "C" {
 #include <libavcodec/avcodec.h>
 #include <libavformat/avio.h>
+#include <libavutil/channel_layout.h>
 }
 
 AUD_NAMESPACE_BEGIN
@@ -171,7 +172,7 @@ FFMPEGWriter::FFMPEGWriter(std::string filename, Devic
 	if(avformat_alloc_output_context2(&m_formatCtx, nullptr, formats[format], filename.c_str()) < 0)
 		AUD_THROW(FileException, "File couldn't be written, format couldn't be found with ffmpeg.");
 
-	AVOutputFormat* outputFmt = m_formatCtx->oformat;
+	AVOutputFormat* outputFmt = const_cast<AVOutputFormat*>(m_formatCtx->oformat);
 
 	if(!outputFmt) {
 		avformat_free_context(m_formatCtx);
@@ -271,7 +272,7 @@ FFMPEGWriter::FFMPEGWriter(std::string filename, Devic
 		if(outputFmt->audio_codec == AV_CODEC_ID_NONE)
 			AUD_THROW(FileException, "File couldn't be written, audio codec not found with ffmpeg.");
 
-		AVCodec* codec = avcodec_find_encoder(outputFmt->audio_codec);
+		const AVCodec* codec = avcodec_find_encoder(outputFmt->audio_codec);
 		if(!codec)
 			AUD_THROW(FileException, "File couldn't be written, audio encoder couldn't be found with ffmpeg.");
 
