- workaround for https://github.com/falkTX/Carla/issues/1867
- Carla was broken by the update of audio/liblo to 0.32

--- source/backend/CarlaPlugin.hpp.orig	2024-03-07 08:16:09 UTC
+++ source/backend/CarlaPlugin.hpp
@@ -24,7 +24,7 @@
 // -----------------------------------------------------------------------
 // Avoid including extra libs here
 
-typedef void* lo_message;
+typedef struct lo_message_ *lo_message;
 typedef struct _NativePluginDescriptor NativePluginDescriptor;
 struct LADSPA_RDF_Descriptor;
 
