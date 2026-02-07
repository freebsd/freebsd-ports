--- src/tse3/file/MidiFilter.cpp.orig	2005-08-23 12:32:31 UTC
+++ src/tse3/file/MidiFilter.cpp
@@ -10,7 +10,7 @@ void TSE3::File::write(XmlFileWriter &wr
     TSE3::File::XmlFileWriter::AutoElement ae(writer, "MidiFilter");
 
     writer.element("Status",        mf.status());
-    unsigned int c_filter = 0, p_filter = 0;
+    size_t c_filter = 0, p_filter = 0;
     for (int n = 0; n < 16; n++) if (mf.channelFilter(n)) c_filter |= (1<<n);
     writer.element("ChannelFilter", c_filter);
     writer.element("PortFilter",    p_filter);
