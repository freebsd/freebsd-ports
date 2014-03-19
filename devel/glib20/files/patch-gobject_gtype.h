--- gobject/gtype.h.orig	2014-03-08 01:02:56.790527382 +0000
+++ gobject/gtype.h	2014-03-08 01:03:33.934524502 +0000
@@ -1674,6 +1674,7 @@
 \
 _G_DEFINE_TYPE_EXTENDED_CLASS_INIT(TypeName, type_name) \
 \
+G_GNUC_UNUSED \
 static inline gpointer \
 type_name##_get_instance_private (TypeName *self) \
 { \
