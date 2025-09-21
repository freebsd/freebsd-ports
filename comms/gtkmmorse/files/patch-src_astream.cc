--- src/astream.cc.orig	2008-02-28 18:08:45 UTC
+++ src/astream.cc
@@ -44,6 +44,7 @@ oastream::oastream()
     m_format.channels = 2;
     m_format.rate = 44100;
     m_format.byte_format = AO_FMT_LITTLE;
+    m_format.matrix=NULL;
 
     ao_initialize();
 }
