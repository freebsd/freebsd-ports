--- src/webp.imageio/webpinput.cpp.orig	2020-12-07 13:21:21 UTC
+++ src/webp.imageio/webpinput.cpp
@@ -136,7 +136,7 @@ WebpInput::open(const std::string& name, ImageSpec& sp
     }

     // WebPMuxError err;
-    WebPData bitstream { m_encoded_image.get(), m_image_size };
+    WebPData bitstream { m_encoded_image.get(), (size_t)m_image_size };
     m_demux = WebPDemux(&bitstream);
     if (!m_demux) {
         errorf("Couldn't decode");
