--- src/decoder/plugins/WildmidiDecoderPlugin.cxx.orig	2014-10-24 22:28:53 UTC
+++ src/decoder/plugins/WildmidiDecoderPlugin.cxx
@@ -94,7 +94,7 @@ wildmidi_file_decode(Decoder &decoder, P
 
 	DecoderCommand cmd;
 	do {
-		char buffer[4096];
+		int8_t buffer[4096];
 		int len;
 
 		info = WildMidi_GetInfo(wm);
