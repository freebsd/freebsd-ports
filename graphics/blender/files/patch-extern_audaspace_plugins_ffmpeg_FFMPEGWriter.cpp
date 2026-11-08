From e3c92c22817dc0310a460c22f6b1e8e397517e3b Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?J=C3=B6rg=20M=C3=BCller?= <nexyon@gmail.com>
Date: Wed, 19 Aug 2026 18:22:35 +0200
Subject: [PATCH] Audaspace: port ffmpeg 9 support from upstream.

--- extern/audaspace/plugins/ffmpeg/FFMPEGWriter.cpp.orig	2025-10-08 10:41:55 UTC
+++ extern/audaspace/plugins/ffmpeg/FFMPEGWriter.cpp
@@ -38,6 +38,10 @@ AUD_NAMESPACE_BEGIN
 #if LIBAVCODEC_VERSION_MAJOR < 59
 #define FFMPEG_OLD_CH_LAYOUT
 #endif
+/* FFmpeg >= 8.0 */
+#if LIBAVCODEC_VERSION_MAJOR >= 62
+#define FFMPEG_SUPPORTED_CONFIG
+#endif
 
 void FFMPEGWriter::encode()
 {
@@ -330,8 +334,106 @@ FFMPEGWriter::FFMPEGWriter(const std::string &filename
 		if(m_formatCtx->oformat->flags & AVFMT_GLOBALHEADER)
 			m_codecCtx->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
 
+#ifdef FFMPEG_SUPPORTED_CONFIG
+		const AVSampleFormat* supported_sample_fmts = nullptr;
+		int num_sample_fmts = 0;
+		if(avcodec_get_supported_config(m_codecCtx, codec, AV_CODEC_CONFIG_SAMPLE_FORMAT, 0,
+										reinterpret_cast<const void**>(&supported_sample_fmts), &num_sample_fmts) < 0)
+			AUD_THROW(FileException, "File couldn't be written, couldn't retrieve supported sample formats.");
+
 		bool format_supported = false;
 
+		if(supported_sample_fmts)
+		{
+			for(int i = 0; i < num_sample_fmts; i++)
+			{
+				if(av_get_alt_sample_fmt(supported_sample_fmts[i], false) == m_codecCtx->sample_fmt)
+				{
+					m_deinterleave = av_sample_fmt_is_planar(supported_sample_fmts[i]);
+					m_codecCtx->sample_fmt = supported_sample_fmts[i];
+					format_supported = true;
+				}
+			}
+
+			if(!format_supported && num_sample_fmts > 0)
+			{
+				int chosen_index = 0;
+				auto chosen = av_get_alt_sample_fmt(supported_sample_fmts[chosen_index], false);
+				for(int i = 1; i < num_sample_fmts; i++)
+				{
+					auto fmt = av_get_alt_sample_fmt(supported_sample_fmts[i], false);
+					if((fmt > chosen && chosen < m_codecCtx->sample_fmt) || (fmt > m_codecCtx->sample_fmt && fmt < chosen))
+					{
+						chosen = fmt;
+						chosen_index = i;
+					}
+				}
+
+				m_codecCtx->sample_fmt = supported_sample_fmts[chosen_index];
+				m_deinterleave = av_sample_fmt_is_planar(m_codecCtx->sample_fmt);
+				switch(av_get_alt_sample_fmt(m_codecCtx->sample_fmt, false))
+				{
+				case AV_SAMPLE_FMT_U8:
+					specs.format = FORMAT_U8;
+					m_convert = convert_float_u8;
+					break;
+				case AV_SAMPLE_FMT_S16:
+					specs.format = FORMAT_S16;
+					m_convert = convert_float_s16;
+					break;
+				case AV_SAMPLE_FMT_S32:
+					specs.format = FORMAT_S32;
+					m_convert = convert_float_s32;
+					break;
+				case AV_SAMPLE_FMT_FLT:
+					specs.format = FORMAT_FLOAT32;
+					m_convert = convert_copy<sample_t>;
+					break;
+				case AV_SAMPLE_FMT_DBL:
+					specs.format = FORMAT_FLOAT64;
+					m_convert = convert_float_double;
+					break;
+				default:
+					AUD_THROW(FileException, "File couldn't be written, sample format not supported with ffmpeg.");
+				}
+			}
+		}
+		else
+		{
+			m_codecCtx->sample_fmt = av_get_alt_sample_fmt(m_codecCtx->sample_fmt, false);
+			m_deinterleave = av_sample_fmt_is_planar(m_codecCtx->sample_fmt);
+		}
+
+		const int* supported_samplerates = nullptr;
+		int num_samplerates = 0;
+		if(avcodec_get_supported_config(m_codecCtx, codec, AV_CODEC_CONFIG_SAMPLE_RATE, 0,
+										reinterpret_cast<const void**>(&supported_samplerates), &num_samplerates) < 0)
+			AUD_THROW(FileException, "File couldn't be written, couldn't retrieve supported sample rates.");
+
+		m_codecCtx->sample_rate = 0;
+
+		if(supported_samplerates)
+		{
+			for(int i = 0; i < num_samplerates; i++)
+			{
+				if(supported_samplerates[i] == m_specs.rate)
+				{
+					m_codecCtx->sample_rate = supported_samplerates[i];
+					break;
+				}
+				else if((supported_samplerates[i] > m_codecCtx->sample_rate && m_specs.rate > m_codecCtx->sample_rate) ||
+						(supported_samplerates[i] < m_codecCtx->sample_rate && m_specs.rate < supported_samplerates[i]))
+				{
+					m_codecCtx->sample_rate = supported_samplerates[i];
+				}
+			}
+		}
+
+		if(m_codecCtx->sample_rate == 0)
+			m_codecCtx->sample_rate = m_specs.rate;
+#else
+		bool format_supported = false;
+
 		for(int i = 0; codec->sample_fmts[i] != -1; i++)
 		{
 			if(av_get_alt_sample_fmt(codec->sample_fmts[i], false) == m_codecCtx->sample_fmt)
@@ -406,6 +508,7 @@ FFMPEGWriter::FFMPEGWriter(const std::string &filename
 
 		if(m_codecCtx->sample_rate == 0)
 			m_codecCtx->sample_rate = m_specs.rate;
+#endif
 
 		m_specs.rate = m_codecCtx->sample_rate;
 
