--- libgnomecanvas/libgnomecanvasmm/line.h.orig	Wed Aug  4 13:38:03 2004
+++ libgnomecanvas/libgnomecanvasmm/line.h	Wed Aug  4 13:38:23 2004
@@ -286,7 +286,7 @@
 {
 
 template <>
-class Glib::Value<Gnome::Canvas::Points> : public Glib::Value_Boxed<Gnome::Canvas::Points>
+class Value<Gnome::Canvas::Points> : public Glib::Value_Boxed<Gnome::Canvas::Points>
 {
 public:
   static GType value_type() G_GNUC_CONST;
