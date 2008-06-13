
$FreeBSD$

--- extensions/gst_mediaplayer_element/gadget_videosink.cc.orig
+++ extensions/gst_mediaplayer_element/gadget_videosink.cc
@@ -17,6 +17,12 @@
 #include "gadget_videosink.h"
 #include <pthread.h>
 
+#if __GNUC__ < 4
+#define CAST_HACK(x) (x)
+#else
+#define CAST_HACK(x) reinterpret_cast<x>
+#endif
+
 namespace ggadget {
 namespace gst {
 
@@ -454,10 +460,10 @@
       nom = gst_value_get_fraction_numerator(videosink->par_);
       den = gst_value_get_fraction_denominator(videosink->par_);
       gst_structure_set(structure, "pixel-aspect-ratio",
-                        GST_TYPE_FRACTION, nom, den, NULL);
+                        GST_TYPE_FRACTION, nom, den, (gchar*)0);
     } else {
       gst_structure_set(structure, "pixel-aspect-ratio",
-                        GST_TYPE_FRACTION, 1, 1, NULL);
+                        GST_TYPE_FRACTION, 1, 1, (gchar*)0);
     }
   }
 
@@ -669,18 +675,18 @@
       desired_caps = gst_caps_copy(caps);
       desired_struct = gst_caps_get_structure(desired_caps, 0);
 
-      gst_structure_set (desired_struct, "width", G_TYPE_INT, result.w, NULL);
-      gst_structure_set (desired_struct, "height", G_TYPE_INT, result.h, NULL);
+      gst_structure_set (desired_struct, "width", G_TYPE_INT, result.w, (gchar*)0);
+      gst_structure_set (desired_struct, "height", G_TYPE_INT, result.h, (gchar*)0);
 
       // PAR property overrides the default one.
       if (videosink->par_) {
         nom = gst_value_get_fraction_numerator(videosink->par_);
         den = gst_value_get_fraction_denominator(videosink->par_);
         gst_structure_set(desired_struct, "pixel-aspect-ratio",
-                           GST_TYPE_FRACTION, nom, den, NULL);
+                           GST_TYPE_FRACTION, nom, den, (gchar*)0);
       } else {
         gst_structure_set(desired_struct, "pixel-aspect-ratio",
-                          GST_TYPE_FRACTION, 1, 1, NULL);
+                          GST_TYPE_FRACTION, 1, 1, (gchar*)0);
       }
 
       // see if peer accepts our new suggestion, if there is no peer, this
@@ -859,7 +865,7 @@
         g_value_transform(videosink->par_, value);
       break;
     case PROP_RECEIVE_IMAGE_HANDLER:
-      g_value_set_pointer(value, reinterpret_cast<void*>(&ReceiveImageHandler));
+      g_value_set_pointer(value, CAST_HACK(void*)(&ReceiveImageHandler));
       break;
     default:
       G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
@@ -892,7 +898,7 @@
   nom = gst_value_get_fraction_numerator(par_);
   den = gst_value_get_fraction_denominator(par_);
   gst_caps_set_simple(caps_, const_cast<gchar*>("pixel-aspect-ratio"),
-                      GST_TYPE_FRACTION, 1, 1, NULL);
+                      GST_TYPE_FRACTION, 1, 1, (gchar*)0);
 }
 
 // This function converts the image format if necessary, puts the image into
