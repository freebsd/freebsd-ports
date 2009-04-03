--- src/tse3/file/MidiFilter.cpp	Tue Aug 23 08:32:31 2005
+++ src/tse3/file/MidiFilter.cpp	Sun Sep 11 20:33:13 2005
@@ -11,5 +11,5 @@
 
     writer.element("Status",        mf.status());
-    unsigned int c_filter = 0, p_filter = 0;
+    size_t c_filter = 0, p_filter = 0;
     for (int n = 0; n < 16; n++) if (mf.channelFilter(n)) c_filter |= (1<<n);
     writer.element("ChannelFilter", c_filter);
