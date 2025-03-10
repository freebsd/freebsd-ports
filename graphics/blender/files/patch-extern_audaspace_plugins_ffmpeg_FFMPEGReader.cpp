--- extern/audaspace/plugins/ffmpeg/FFMPEGReader.cpp.orig	2024-08-18 04:20:22 UTC
+++ extern/audaspace/plugins/ffmpeg/FFMPEGReader.cpp
@@ -31,6 +31,10 @@ AUD_NAMESPACE_BEGIN
 #define FFMPEG_OLD_CODE
 #endif
 
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+#define HAVE_CH_LAYOUT
+#endif
+
 SampleFormat FFMPEGReader::convertSampleFormat(AVSampleFormat format)
 {
 	switch(av_get_packed_sample_fmt(format))
@@ -109,10 +113,16 @@ int FFMPEGReader::decode(AVPacket& packet, Buffer& buf
 	{
 		auto ret = avcodec_receive_frame(m_codecCtx, m_frame);
 
+#ifdef HAVE_CH_LAYOUT
+		int nb_channels = m_codecCtx->ch_layout.nb_channels;
+#else
+		int nb_channels = m_codecCtx->channels;
+#endif
+
 		if(ret != 0)
 			break;
 
-		int data_size = av_samples_get_buffer_size(nullptr, m_codecCtx->channels, m_frame->nb_samples, m_codecCtx->sample_fmt, 1);
+		int data_size = av_samples_get_buffer_size(nullptr, nb_channels, m_frame->nb_samples, m_codecCtx->sample_fmt, 1);
 
 		if(buf_size - buf_pos < data_size)
 		{
@@ -122,12 +132,12 @@ int FFMPEGReader::decode(AVPacket& packet, Buffer& buf
 
 		if(m_tointerleave)
 		{
-			int single_size = data_size / m_codecCtx->channels / m_frame->nb_samples;
-			for(int channel = 0; channel < m_codecCtx->channels; channel++)
+			int single_size = data_size / nb_channels / m_frame->nb_samples;
+			for(int channel = 0; channel < nb_channels; channel++)
 			{
 				for(int i = 0; i < m_frame->nb_samples; i++)
 				{
-					std::memcpy(((data_t*)buffer.getBuffer()) + buf_pos + ((m_codecCtx->channels * i) + channel) * single_size,
+					std::memcpy(((data_t*)buffer.getBuffer()) + buf_pos + ((nb_channels * i) + channel) * single_size,
 						   m_frame->data[channel] + i * single_size, single_size);
 				}
 			}
@@ -207,7 +217,11 @@ void FFMPEGReader::init(int stream)
 	if(avcodec_open2(m_codecCtx, aCodec, nullptr) < 0)
 		AUD_THROW(FileException, "File couldn't be read, ffmpeg codec couldn't be opened.");
 
+#ifdef HAVE_CH_LAYOUT
+	m_specs.channels = (Channels) m_codecCtx->ch_layout.nb_channels;
+#else
 	m_specs.channels = (Channels) m_codecCtx->channels;
+#endif
 	m_tointerleave = av_sample_fmt_is_planar(m_codecCtx->sample_fmt);
 
 	switch(av_get_packed_sample_fmt(m_codecCtx->sample_fmt))
@@ -345,7 +359,11 @@ std::vector<StreamInfo> FFMPEGReader::queryStreams()
 			info.specs.rate = m_formatCtx->streams[i]->codec->sample_rate;
 			info.specs.format = convertSampleFormat(m_formatCtx->streams[i]->codec->sample_fmt);
 #else
+#ifdef HAVE_CH_LAYOUT
+			info.specs.channels = Channels(m_formatCtx->streams[i]->codecpar->ch_layout.nb_channels);
+#else
 			info.specs.channels = Channels(m_formatCtx->streams[i]->codecpar->channels);
+#endif
 			info.specs.rate = m_formatCtx->streams[i]->codecpar->sample_rate;
 			info.specs.format = convertSampleFormat(AVSampleFormat(m_formatCtx->streams[i]->codecpar->format));
 #endif
