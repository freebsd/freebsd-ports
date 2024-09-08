--- extern/audaspace/plugins/ffmpeg/FFMPEGWriter.cpp.orig	2024-08-18 04:25:16 UTC
+++ extern/audaspace/plugins/ffmpeg/FFMPEGWriter.cpp
@@ -34,6 +34,10 @@ AUD_NAMESPACE_BEGIN
 #define FFMPEG_OLD_CODE
 #endif
 
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+#define HAVE_CH_LAYOUT
+#endif
+
 void FFMPEGWriter::encode()
 {
 	sample_t* data = m_input_buffer.getBuffer();
@@ -77,8 +81,12 @@ void FFMPEGWriter::encode()
 
 	m_frame->nb_samples = m_input_samples;
 	m_frame->format = m_codecCtx->sample_fmt;
+#ifdef HAVE_CH_LAYOUT
+	av_channel_layout_copy(&m_frame->ch_layout, &m_codecCtx->ch_layout);
+#else
 	m_frame->channel_layout = m_codecCtx->channel_layout;
 	m_frame->channels = m_specs.channels;
+#endif
 
 	if(avcodec_fill_audio_frame(m_frame, m_specs.channels, m_codecCtx->sample_fmt, reinterpret_cast<data_t*>(data), m_input_buffer.getSize(), 0) < 0)
 		AUD_THROW(FileException, "File couldn't be written, filling the audio frame failed with ffmpeg.");
@@ -237,6 +245,39 @@ FFMPEGWriter::FFMPEGWriter(const std::string &filename
 		break;
 	}
 
+#ifdef HAVE_CH_LAYOUT
+	AVChannelLayout channel_layout{};
+
+	switch(m_specs.channels)
+	{
+	case CHANNELS_MONO:
+		channel_layout = AV_CHANNEL_LAYOUT_MONO;
+		break;
+	case CHANNELS_STEREO:
+		channel_layout = AV_CHANNEL_LAYOUT_STEREO;
+		break;
+	case CHANNELS_STEREO_LFE:
+		channel_layout = AV_CHANNEL_LAYOUT_2POINT1;
+		break;
+	case CHANNELS_SURROUND4:
+		channel_layout = AV_CHANNEL_LAYOUT_QUAD;
+		break;
+	case CHANNELS_SURROUND5:
+		channel_layout = AV_CHANNEL_LAYOUT_5POINT0_BACK;
+		break;
+	case CHANNELS_SURROUND51:
+		channel_layout = AV_CHANNEL_LAYOUT_5POINT1_BACK;
+		break;
+	case CHANNELS_SURROUND61:
+		channel_layout = AV_CHANNEL_LAYOUT_6POINT1_BACK;
+		break;
+	case CHANNELS_SURROUND71:
+		channel_layout = AV_CHANNEL_LAYOUT_7POINT1;
+		break;
+	default:
+		AUD_THROW(FileException, "File couldn't be written, channel layout not supported.");
+	}
+#else
 	uint64_t channel_layout = 0;
 
 	switch(m_specs.channels)
@@ -268,6 +309,7 @@ FFMPEGWriter::FFMPEGWriter(const std::string &filename
 	default:
 		AUD_THROW(FileException, "File couldn't be written, channel layout not supported.");
 	}
+#endif
 
 	try
 	{
@@ -405,8 +447,12 @@ FFMPEGWriter::FFMPEGWriter(const std::string &filename
 
 		m_codecCtx->codec_type = AVMEDIA_TYPE_AUDIO;
 		m_codecCtx->bit_rate = bitrate;
+#ifdef HAVE_CH_LAYOUT
+		av_channel_layout_copy(&m_codecCtx->ch_layout, &channel_layout);
+#else
 		m_codecCtx->channel_layout = channel_layout;
 		m_codecCtx->channels = m_specs.channels;
+#endif
 		m_stream->time_base.num = m_codecCtx->time_base.num = 1;
 		m_stream->time_base.den = m_codecCtx->time_base.den = m_codecCtx->sample_rate;
 
