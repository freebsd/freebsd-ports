--- extern/audaspace/plugins/ffmpeg/FFMPEGReader.cpp.orig	2025-12-28 19:03:48 UTC
+++ extern/audaspace/plugins/ffmpeg/FFMPEGReader.cpp
@@ -255,13 +255,7 @@ void FFMPEGReader::init(int stream)
 	m_specs.rate = (SampleRate) m_codecCtx->sample_rate;
 }
 
-FFMPEGReader::FFMPEGReader(const std::string &filename, int stream) :
-	m_pkgbuf(),
-	m_formatCtx(nullptr),
-	m_codecCtx(nullptr),
-	m_frame(nullptr),
-	m_aviocontext(nullptr),
-	m_membuf(nullptr)
+FFMPEGReader::FFMPEGReader(const std::string& filename, int stream) : m_pkgbuf(), m_formatCtx(nullptr), m_codecCtx(nullptr), m_frame(nullptr), m_aviocontext(nullptr)
 {
 	// open file
 	if(avformat_open_input(&m_formatCtx, filename.c_str(), nullptr, nullptr)!=0)
@@ -285,13 +279,15 @@ FFMPEGReader::FFMPEGReader(std::shared_ptr<Buffer> buffer, int stream) :
 		m_membuffer(buffer),
 		m_membufferpos(0)
 {
-	m_membuf = reinterpret_cast<data_t*>(av_malloc(AV_INPUT_BUFFER_MIN_SIZE + AV_INPUT_BUFFER_PADDING_SIZE));
+	constexpr int BUFFER_SIZE{4096};
 
-	m_aviocontext = avio_alloc_context(m_membuf, AV_INPUT_BUFFER_MIN_SIZE, 0, this, read_packet, nullptr, seek_packet);
+	auto membuf = reinterpret_cast<data_t*>(av_malloc(BUFFER_SIZE));
+
+	m_aviocontext = avio_alloc_context(membuf, BUFFER_SIZE, 0, this, read_packet, nullptr, seek_packet);
 
 	if(!m_aviocontext)
 	{
-		av_free(m_aviocontext);
+		av_free(membuf);
 		AUD_THROW(FileException, "Buffer reading context couldn't be created with ffmpeg.");
 	}
 
@@ -299,6 +295,8 @@ FFMPEGReader::FFMPEGReader(std::shared_ptr<Buffer> buffer, int stream) :
 	m_formatCtx->pb = m_aviocontext;
 	if(avformat_open_input(&m_formatCtx, "", nullptr, nullptr)!=0)
 	{
+		if(m_aviocontext->buffer)
+			av_free(m_aviocontext->buffer);
 		av_free(m_aviocontext);
 		AUD_THROW(FileException, "Buffer couldn't be read with ffmpeg.");
 	}
@@ -310,6 +308,8 @@ FFMPEGReader::FFMPEGReader(std::shared_ptr<Buffer> buffer, int stream) :
 	catch(Exception&)
 	{
 		avformat_close_input(&m_formatCtx);
+		if(m_aviocontext->buffer)
+			av_free(m_aviocontext->buffer);
 		av_free(m_aviocontext);
 		throw;
 	}
@@ -325,6 +325,13 @@ FFMPEGReader::~FFMPEGReader()
 	if(m_codecCtx)
 		avcodec_free_context(&m_codecCtx);
 #endif
+	if(m_aviocontext)
+	{
+		if(m_aviocontext->buffer)
+			av_free(m_aviocontext->buffer);
+		av_free(m_aviocontext);
+	}
+
 	avformat_close_input(&m_formatCtx);
 }
 
