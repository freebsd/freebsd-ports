--- src/osgPlugins/ffmpeg/ReaderWriterFFmpeg.cpp.orig	2022-12-01 18:17:31 UTC
+++ src/osgPlugins/ffmpeg/ReaderWriterFFmpeg.cpp
@@ -10,7 +10,6 @@
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * OpenSceneGraph Public License for more details.
 */
-
 #include "FFmpegHeaders.hpp"
 #include "FFmpegImageStream.hpp"
 #include "FFmpegParameters.hpp"
@@ -19,13 +18,6 @@
 #include <osgDB/FileNameUtils>
 #include <osgDB/FileUtils>
 
-
-#if LIBAVCODEC_VERSION_MAJOR >= 53 || \
-    (LIBAVCODEC_VERSION_MAJOR==52 && LIBAVCODEC_VERSION_MINOR>=30) || \
-    (LIBAVCODEC_VERSION_MAJOR==52 && LIBAVCODEC_VERSION_MINOR==20 && LIBAVCODEC_VERSION_MICRO >= 1)
-    #define USE_AV_LOCK_MANAGER
-#endif
-
 extern "C" {
 
 static void log_to_osg(void* /*ptr*/, int level, const char *fmt, va_list vl)
@@ -100,26 +92,21 @@ class ReaderWriterFFmpeg : public osgDB::ReaderWriter 
 
         supportsOption("format",            "Force setting input format (e.g. vfwcap for Windows webcam)");
         supportsOption("pixel_format",      "Set pixel format");
-        supportsOption("frame_size",              "Set frame size (e.g. 320x240)");
+        supportsOption("frame_size",        "Set frame size (e.g. 320x240)");
         supportsOption("frame_rate",        "Set frame rate (e.g. 25)");
         // WARNING:  This option is kept for backwards compatibility only, use out_sample_rate instead!
         supportsOption("audio_sample_rate", "Set audio sampling rate (e.g. 44100)");
         supportsOption("out_sample_format", "Set the output sample format (e.g. AV_SAMPLE_FMT_S16)");
-        supportsOption("out_sample_rate",     "Set the output sample rate or frequency in Hz (e.g. 48000)");
+        supportsOption("out_sample_rate",   "Set the output sample rate or frequency in Hz (e.g. 48000)");
         supportsOption("out_nb_channels",   "Set the output number of channels (e.g. 2 for stereo)");
-        supportsOption("context",            "AVIOContext* for custom IO");
-        supportsOption("mad",            "Max analyze duration (seconds)");
-        supportsOption("rtsp_transport", "RTSP transport (udp, tcp, udp_multicast or http)");
+        supportsOption("context",           "AVIOContext* for custom IO");
+        supportsOption("mad",               "Max analyze duration (seconds)");
+        supportsOption("rtsp_transport",    "RTSP transport (udp, tcp, udp_multicast or http)");
 
         av_log_set_callback(log_to_osg);
 
-#ifdef USE_AV_LOCK_MANAGER
-        // enable thread locking
-        av_lockmgr_register(&lockMgr);
-#endif
         // Register all FFmpeg formats/codecs
-        av_register_all();
-
+        avdevice_register_all();
         avformat_network_init();
     }
 
@@ -218,41 +205,7 @@ class ReaderWriterFFmpeg : public osgDB::ReaderWriter 
             }
         }
     }
-
-#ifdef USE_AV_LOCK_MANAGER
-    static int lockMgr(void **mutex, enum AVLockOp op)
-    {
-        // returns are 0 success
-        OpenThreads::Mutex **m=(OpenThreads::Mutex**)mutex;
-        if (op==AV_LOCK_CREATE)
-        {
-            *m=new OpenThreads::Mutex;
-            return !*m;
-        }
-        else if (op==AV_LOCK_DESTROY)
-        {
-            delete *m;
-            return 0;
-        }
-        else if (op==AV_LOCK_OBTAIN)
-        {
-            (*m)->lock();
-            return 0;
-        }
-        else if (op==AV_LOCK_RELEASE)
-        {
-            (*m)->unlock();
-            return 0;
-        }
-        else
-        {
-            return -1;
-        }
-    }
-#endif
-
 };
 
-
-
 REGISTER_OSGPLUGIN(ffmpeg, ReaderWriterFFmpeg)
+
