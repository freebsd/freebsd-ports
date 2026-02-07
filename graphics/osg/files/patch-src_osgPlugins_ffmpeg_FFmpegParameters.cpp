--- src/osgPlugins/ffmpeg/FFmpegParameters.cpp.orig	2022-12-01 18:17:31 UTC
+++ src/osgPlugins/ffmpeg/FFmpegParameters.cpp
@@ -1,4 +1,3 @@
-
 #include "FFmpegParameters.hpp"
 
 #include <string>
@@ -21,11 +20,8 @@ inline AVPixelFormat osg_av_get_pix_fmt(const char *na
 
 inline AVPixelFormat osg_av_get_pix_fmt(const char *name) { return av_get_pix_fmt(name); }
 
-
 namespace osgFFmpeg {
 
-
-
 FFmpegParameters::FFmpegParameters() :
     m_format(0),
     m_context(0),
@@ -40,7 +36,6 @@ FFmpegParameters::~FFmpegParameters()
     av_dict_free(&m_options);
 }
 
-
 void FFmpegParameters::parse(const std::string& name, const std::string& value)
 {
     if (value.empty())
@@ -52,7 +47,8 @@ void FFmpegParameters::parse(const std::string& name, 
 #ifndef ANDROID
         avdevice_register_all();
 #endif
-        m_format = av_find_input_format(value.c_str());
+        const AVInputFormat* format = av_find_input_format(value.c_str());
+        m_format = const_cast<AVInputFormat*>(format);
         if (!m_format)
             OSG_NOTICE<<"Failed to apply input video format: "<<value.c_str()<<std::endl;
     }
