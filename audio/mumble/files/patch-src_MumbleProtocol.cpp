--- src/MumbleProtocol.cpp.orig	2024-03-03 17:26:27 UTC
+++ src/MumbleProtocol.cpp
@@ -781,7 +781,7 @@ namespace Protocol {
 		}
 
 
-		m_audioData.payload = gsl::span< byte >(payloadBegin, payloadSize);
+		m_audioData.payload = gsl::span< byte >(payloadBegin, static_cast< size_t >(payloadSize));
 
 		if (stream.left() == 3 * sizeof(float)) {
 			// If there are further bytes after the audio payload, this means that there is positional data attached to
