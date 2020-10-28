--- modules/javafx.media/src/main/native/gstreamer/gstreamer-lite/gstreamer/gst/gst_private.h.orig	2020-07-17 12:21:33 UTC
+++ modules/javafx.media/src/main/native/gstreamer/gstreamer-lite/gstreamer/gst/gst_private.h
@@ -237,12 +237,12 @@ GstCapsFeatures * __gst_caps_get_features_unchecked (c
 #ifndef GST_DISABLE_REGISTRY
 /* Secret variable to initialise gst without registry cache */
 
-GST_API gboolean _gst_disable_registry_cache;
+extern GST_API gboolean _gst_disable_registry_cache;
 #endif
 
 /* Secret variable to let the plugin scanner use the same base path
  * as the main application in order to determine dependencies */
-GST_API gchar *_gst_executable_path;
+extern GST_API gchar *_gst_executable_path;
 
 /* provide inline gst_g_value_get_foo_unchecked(), used in gststructure.c */
 #define DEFINE_INLINE_G_VALUE_GET_UNCHECKED(ret_type,name_type,v_field) \
@@ -266,37 +266,37 @@ DEFINE_INLINE_G_VALUE_GET_UNCHECKED(const gchar *,stri
 
 #ifndef GST_REMOVE_GST_DEBUG
 
-GST_API GstDebugCategory *GST_CAT_GST_INIT;
-GST_API GstDebugCategory *GST_CAT_MEMORY;
-GST_API GstDebugCategory *GST_CAT_PARENTAGE;
-GST_API GstDebugCategory *GST_CAT_STATES;
-GST_API GstDebugCategory *GST_CAT_SCHEDULING;
-GST_API GstDebugCategory *GST_CAT_BUFFER;
-GST_API GstDebugCategory *GST_CAT_BUFFER_LIST;
-GST_API GstDebugCategory *GST_CAT_BUS;
-GST_API GstDebugCategory *GST_CAT_CAPS;
-GST_API GstDebugCategory *GST_CAT_CLOCK;
-GST_API GstDebugCategory *GST_CAT_ELEMENT_PADS;
-GST_API GstDebugCategory *GST_CAT_PADS;
-GST_API GstDebugCategory *GST_CAT_PERFORMANCE;
-GST_API GstDebugCategory *GST_CAT_PIPELINE;
-GST_API GstDebugCategory *GST_CAT_PLUGIN_LOADING;
-GST_API GstDebugCategory *GST_CAT_PLUGIN_INFO;
-GST_API GstDebugCategory *GST_CAT_PROPERTIES;
-GST_API GstDebugCategory *GST_CAT_NEGOTIATION;
-GST_API GstDebugCategory *GST_CAT_REFCOUNTING;
-GST_API GstDebugCategory *GST_CAT_ERROR_SYSTEM;
-GST_API GstDebugCategory *GST_CAT_EVENT;
-GST_API GstDebugCategory *GST_CAT_MESSAGE;
-GST_API GstDebugCategory *GST_CAT_PARAMS;
-GST_API GstDebugCategory *GST_CAT_CALL_TRACE;
-GST_API GstDebugCategory *GST_CAT_SIGNAL;
-GST_API GstDebugCategory *GST_CAT_PROBE;
-GST_API GstDebugCategory *GST_CAT_REGISTRY;
-GST_API GstDebugCategory *GST_CAT_QOS;
-GST_API GstDebugCategory *GST_CAT_META;
-GST_API GstDebugCategory *GST_CAT_LOCKING;
-GST_API GstDebugCategory *GST_CAT_CONTEXT;
+extern GST_API GstDebugCategory *GST_CAT_GST_INIT;
+extern GST_API GstDebugCategory *GST_CAT_MEMORY;
+extern GST_API GstDebugCategory *GST_CAT_PARENTAGE;
+extern GST_API GstDebugCategory *GST_CAT_STATES;
+extern GST_API GstDebugCategory *GST_CAT_SCHEDULING;
+extern GST_API GstDebugCategory *GST_CAT_BUFFER;
+extern GST_API GstDebugCategory *GST_CAT_BUFFER_LIST;
+extern GST_API GstDebugCategory *GST_CAT_BUS;
+extern GST_API GstDebugCategory *GST_CAT_CAPS;
+extern GST_API GstDebugCategory *GST_CAT_CLOCK;
+extern GST_API GstDebugCategory *GST_CAT_ELEMENT_PADS;
+extern GST_API GstDebugCategory *GST_CAT_PADS;
+extern GST_API GstDebugCategory *GST_CAT_PERFORMANCE;
+extern GST_API GstDebugCategory *GST_CAT_PIPELINE;
+extern GST_API GstDebugCategory *GST_CAT_PLUGIN_LOADING;
+extern GST_API GstDebugCategory *GST_CAT_PLUGIN_INFO;
+extern GST_API GstDebugCategory *GST_CAT_PROPERTIES;
+extern GST_API GstDebugCategory *GST_CAT_NEGOTIATION;
+extern GST_API GstDebugCategory *GST_CAT_REFCOUNTING;
+extern GST_API GstDebugCategory *GST_CAT_ERROR_SYSTEM;
+extern GST_API GstDebugCategory *GST_CAT_EVENT;
+extern GST_API GstDebugCategory *GST_CAT_MESSAGE;
+extern GST_API GstDebugCategory *GST_CAT_PARAMS;
+extern GST_API GstDebugCategory *GST_CAT_CALL_TRACE;
+extern GST_API GstDebugCategory *GST_CAT_SIGNAL;
+extern GST_API GstDebugCategory *GST_CAT_PROBE;
+extern GST_API GstDebugCategory *GST_CAT_REGISTRY;
+extern GST_API GstDebugCategory *GST_CAT_QOS;
+extern GST_API GstDebugCategory *GST_CAT_META;
+extern GST_API GstDebugCategory *GST_CAT_LOCKING;
+extern GST_API GstDebugCategory *GST_CAT_CONTEXT;
 
 /* Categories that should be completely private to
  * libgstreamer should be done like this: */
