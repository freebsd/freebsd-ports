--- src/astream.cc.orig	2008-01-30 09:02:57.000000000 -0800
+++ src/astream.cc	2012-04-26 20:04:36.000000000 -0700
@@ -44,6 +44,7 @@
     m_format.channels = 2;
     m_format.rate = 44100;
     m_format.byte_format = AO_FMT_LITTLE;
+    m_format.matrix=NULL;
 
     ao_initialize();
 }
