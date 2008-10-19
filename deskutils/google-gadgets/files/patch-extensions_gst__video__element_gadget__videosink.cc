
$FreeBSD$

--- extensions/gst_video_element/gadget_videosink.cc.orig
+++ extensions/gst_video_element/gadget_videosink.cc
@@ -459,10 +459,10 @@
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
 
@@ -672,18 +672,18 @@
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
+			  GST_TYPE_FRACTION, nom, den, (gchar*)0);
       } else {
         gst_structure_set(desired_struct, "pixel-aspect-ratio",
-                          GST_TYPE_FRACTION, 1, 1, NULL);
+                          GST_TYPE_FRACTION, 1, 1, (gchar*)0);
       }
 
       // see if peer accepts our new suggestion, if there is no peer, this
@@ -895,7 +895,7 @@
   nom = gst_value_get_fraction_numerator(par_);
   den = gst_value_get_fraction_denominator(par_);
   gst_caps_set_simple(caps_, const_cast<gchar*>("pixel-aspect-ratio"),
-                      GST_TYPE_FRACTION, 1, 1, NULL);
+                      GST_TYPE_FRACTION, 1, 1, (gchar*)0);
 }
 
 // This function converts the image format if necessary, puts the image into
