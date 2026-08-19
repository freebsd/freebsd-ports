See: https://github.com/PCSX2/pcsx2/pull/14831/

From b6cccd87e65a3204cf8154a479f6b3849c1c18d9 Mon Sep 17 00:00:00 2001
From: KamFretoZ <14798312+kamfretoz@users.noreply.github.com>
Date: Sat, 8 Aug 2026 18:52:32 +0700
Subject: [PATCH] GSCapture: Switch the use of `pix_fmts` with
 `avcodec_get_supported_config()`

--- pcsx2/GS/GSCapture.cpp.orig	2026-01-28 16:36:27 UTC
+++ pcsx2/GS/GSCapture.cpp
@@ -67,6 +67,7 @@ extern "C" {
 	X(avcodec_receive_packet) \
 	X(avcodec_parameters_from_context) \
 	X(avcodec_get_hw_config) \
+	X(avcodec_get_supported_config) \
 	X(av_codec_iterate) \
 	X(av_packet_alloc) \
 	X(av_packet_free) \
@@ -454,14 +455,16 @@ bool GSCapture::BeginCapture(float fps, GSVector2i rec
 		// Default to NV12 if not overridden by the user
 		const AVPixelFormat preferred_sw_pix_fmt = GSConfig.VideoCaptureFormat.empty() ? AV_PIX_FMT_NV12 : static_cast<AVPixelFormat>(std::stoi(GSConfig.VideoCaptureFormat));
 		AVPixelFormat sw_pix_fmt = preferred_sw_pix_fmt;
-		if (vcodec->pix_fmts)
+		const AVPixelFormat* supported_pix_fmts = nullptr;
+		if (wrap_avcodec_get_supported_config(nullptr, vcodec, AV_CODEC_CONFIG_PIX_FORMAT, 0,
+				reinterpret_cast<const void**>(&supported_pix_fmts), nullptr) == 0 && supported_pix_fmts)
 		{
-			sw_pix_fmt = vcodec->pix_fmts[0];
-			for (u32 i = 0; vcodec->pix_fmts[i] != AV_PIX_FMT_NONE; i++)
+			sw_pix_fmt = supported_pix_fmts[0];
+			for (u32 i = 0; supported_pix_fmts[i] != AV_PIX_FMT_NONE; i++)
 			{
-				if (vcodec->pix_fmts[i] == preferred_sw_pix_fmt)
+				if (supported_pix_fmts[i] == preferred_sw_pix_fmt)
 				{
-					sw_pix_fmt = vcodec->pix_fmts[i];
+					sw_pix_fmt = supported_pix_fmts[i];
 					break;
 				}
 			}
@@ -686,18 +689,28 @@ bool GSCapture::BeginCapture(float fps, GSVector2i rec
 #endif
 
 		bool supports_format = false;
-		for (const AVSampleFormat* p = acodec->sample_fmts; *p != AV_SAMPLE_FMT_NONE; p++)
+		const AVSampleFormat* supported_sample_fmts = nullptr;
+		if (wrap_avcodec_get_supported_config(nullptr, acodec, AV_CODEC_CONFIG_SAMPLE_FORMAT, 0,
+				reinterpret_cast<const void**>(&supported_sample_fmts), nullptr) == 0 && supported_sample_fmts)
 		{
-			if (*p == s_audio_codec_context->sample_fmt)
+			for (const AVSampleFormat* p = supported_sample_fmts; *p != AV_SAMPLE_FMT_NONE; p++)
 			{
-				supports_format = true;
-				break;
+				if (*p == s_audio_codec_context->sample_fmt)
+				{
+					supports_format = true;
+					break;
+				}
 			}
 		}
+		else
+		{
+			supports_format = true;
+		}
+
 		if (!supports_format)
 		{
 			Console.WriteLn(fmt::format("Audio codec '{}' does not support S16 samples, using default.", acodec->name));
-			s_audio_codec_context->sample_fmt = acodec->sample_fmts[0];
+			s_audio_codec_context->sample_fmt = supported_sample_fmts[0];
 			s_swr_context = wrap_swr_alloc();
 			if (!s_swr_context)
 			{
@@ -1532,16 +1545,18 @@ GSCapture::FormatList GSCapture::GetVideoFormatList(co
 		return ret;
 	}
 
+	const AVPixelFormat* pix_fmts = nullptr;
 	// rawvideo doesn't have a list of formats.
-	if (v_codec->pix_fmts == nullptr)
+	if (wrap_avcodec_get_supported_config(nullptr, v_codec, AV_CODEC_CONFIG_PIX_FORMAT, 0,
+			reinterpret_cast<const void**>(&pix_fmts), nullptr) != 0 || !pix_fmts)
 	{
-		Console.Error("(GetVideoFormatList) v_codec->pix_fmts is null.");
+		Console.Error("(GetVideoFormatList) v_codec has no pixel format list.");
 		return ret;
 	}
 
-	for (int i = 0; v_codec->pix_fmts[i] != AVPixelFormat::AV_PIX_FMT_NONE; i++)
+	for (int i = 0; pix_fmts[i] != AVPixelFormat::AV_PIX_FMT_NONE; i++)
 	{
-		ret.emplace_back(v_codec->pix_fmts[i], wrap_av_get_pix_fmt_name(v_codec->pix_fmts[i]));
+		ret.emplace_back(pix_fmts[i], wrap_av_get_pix_fmt_name(pix_fmts[i]));
 	}
 
 	return ret;
