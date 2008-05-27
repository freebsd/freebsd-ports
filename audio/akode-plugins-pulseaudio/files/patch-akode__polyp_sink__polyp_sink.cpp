--- akode/plugins/polyp_sink/polyp_sink.cpp.orig	Sun Jun 10 13:23:03 2007
+++ akode/plugins/polyp_sink/polyp_sink.cpp	Sun Jun 10 13:24:13 2007
@@ -25,7 +25,7 @@
 #elif defined(HAVE_INTTYPES_H)
 #include <inttypes.h>
 #endif
-#include <polyp/polyplib-simple.h>
+#include <pulse/simple.h>
 
 #include "audioframe.h"
 #include "audiobuffer.h"
@@ -59,7 +59,7 @@
 
 bool PolypSink::open() {
     int error = 0;
-    m_data->server = pa_simple_new(0, "akode-client", PA_STREAM_PLAYBACK, 0, "", &m_data->sample_spec, 0, 255, &error );
+    m_data->server = pa_simple_new(0, "akode-client", PA_STREAM_PLAYBACK, 0, "", &m_data->sample_spec, 0, 0, &error );
     if (!m_data->server || error != 0) {
         m_data->error = true;
         close();
