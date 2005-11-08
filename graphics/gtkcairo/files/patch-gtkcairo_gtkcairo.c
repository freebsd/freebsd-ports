--- gtkcairo/gtkcairo.c.orig	Mon Aug  9 12:19:11 2004
+++ gtkcairo/gtkcairo.c	Tue Nov  8 01:45:10 2005
@@ -25,29 +25,23 @@
 #include "gdkcairo.h"
 #include "gtkcairo.h"
 
-enum {
-	PAINT,
-	LAST_SIGNAL
+enum
+{
+  PAINT,
+  LAST_SIGNAL
 };
 
-static void
-gtk_cairo_class_init            (GtkCairoClass *klass);
+static void gtk_cairo_class_init (GtkCairoClass * klass);
 
-static void
-gtk_cairo_init                  (GtkCairo *gtkcairo);
+static void gtk_cairo_init (GtkCairo *gtkcairo);
 
-static void
-gtk_cairo_destroy               (GtkObject *object);
+static void gtk_cairo_destroy (GtkObject *object);
 
-static void
-gtk_cairo_realize               (GtkWidget *widget);
+static void gtk_cairo_realize (GtkWidget *widget);
 
 static void
-gtk_cairo_size_allocate         (GtkWidget     *widget,
-                                 GtkAllocation *allocation);
-static gint
-gtk_cairo_expose                (GtkWidget      *widget,
-                                 GdkEventExpose *event);
+gtk_cairo_size_allocate (GtkWidget *widget, GtkAllocation * allocation);
+static gint gtk_cairo_expose (GtkWidget *widget, GdkEventExpose *event);
 
 static GtkWidgetClass *parent_class = NULL;
 static guint signals[LAST_SIGNAL] = { 0 };
@@ -57,163 +51,163 @@
 GType
 gtk_cairo_get_type (void)
 {
-	static GType gtk_cairo_type = 0;
+  static GType gtk_cairo_type = 0;
 
-	if (!gtk_cairo_type) {
-		static const GTypeInfo gtk_cairo_info = {
-			sizeof (GtkCairoClass),
-			NULL,
-			NULL,
-			(GClassInitFunc) gtk_cairo_class_init,
-			NULL,
-			NULL,
-			sizeof (GtkCairo),
-			0,
-			(GInstanceInitFunc) gtk_cairo_init,
-		};
+  if (!gtk_cairo_type)
+    {
+      static const GTypeInfo gtk_cairo_info = {
+        sizeof (GtkCairoClass),
+        NULL,
+        NULL,
+        (GClassInitFunc) gtk_cairo_class_init,
+        NULL,
+        NULL,
+        sizeof (GtkCairo),
+        0,
+        (GInstanceInitFunc) gtk_cairo_init,
+      };
 
-		gtk_cairo_type = g_type_register_static (GTK_TYPE_WIDGET, "GtkCairo",
-				                                 &gtk_cairo_info, 0);
-	}
+      gtk_cairo_type = g_type_register_static (GTK_TYPE_WIDGET, "GtkCairo",
+                                               &gtk_cairo_info, 0);
+    }
 
-	return gtk_cairo_type;
+  return gtk_cairo_type;
 }
 
 static void
-gtk_cairo_class_init (GtkCairoClass *class)
+gtk_cairo_class_init (GtkCairoClass * class)
 {
-	GtkObjectClass *object_class;
-	GtkWidgetClass *widget_class;
+  GtkObjectClass *object_class;
+  GtkWidgetClass *widget_class;
 
-	object_class = (GtkObjectClass*) class;
-	widget_class = (GtkWidgetClass*) class;
+  object_class = (GtkObjectClass *) class;
+  widget_class = (GtkWidgetClass *) class;
 
-	parent_class = gtk_type_class(GTK_TYPE_WIDGET);
+  parent_class = gtk_type_class (GTK_TYPE_WIDGET);
 
-	object_class->destroy = gtk_cairo_destroy;
+  object_class->destroy = gtk_cairo_destroy;
 
-	widget_class->realize = gtk_cairo_realize;
-	widget_class->expose_event = gtk_cairo_expose;
-	widget_class->size_allocate = gtk_cairo_size_allocate;
+  widget_class->realize = gtk_cairo_realize;
+  widget_class->expose_event = gtk_cairo_expose;
+  widget_class->size_allocate = gtk_cairo_size_allocate;
 
-	signals[PAINT] = g_signal_new ("paint",
-			GTK_TYPE_CAIRO,
-			G_SIGNAL_RUN_LAST,
-			G_STRUCT_OFFSET (GtkCairoClass, paint),
-			NULL, NULL,
-			g_cclosure_marshal_VOID__POINTER,
-			G_TYPE_NONE, 1, G_TYPE_POINTER);
+  signals[PAINT] = g_signal_new ("paint",
+                                 GTK_TYPE_CAIRO,
+                                 G_SIGNAL_RUN_LAST,
+                                 G_STRUCT_OFFSET (GtkCairoClass, paint),
+                                 NULL, NULL,
+                                 g_cclosure_marshal_VOID__POINTER,
+                                 G_TYPE_NONE, 1, G_TYPE_POINTER);
 }
 
 static void
 gtk_cairo_init (GtkCairo *gtkcairo)
 {
-	gtkcairo->gdkcairo = gdkcairo_new (GTK_WIDGET (gtkcairo));
+  gtkcairo->gdkcairo = gdkcairo_new (GTK_WIDGET (gtkcairo));
 }
 
 GtkWidget *
 gtk_cairo_new (void)
 {
-	GtkWidget *gtkcairo;
-	gtkcairo = GTK_WIDGET (g_object_new (GTK_TYPE_CAIRO, NULL));
+  GtkWidget *gtkcairo;
+  gtkcairo = GTK_WIDGET (g_object_new (GTK_TYPE_CAIRO, NULL));
 
-	gtk_widget_queue_draw (GTK_WIDGET (gtkcairo));
+  gtk_widget_queue_draw (GTK_WIDGET (gtkcairo));
 
-	return gtkcairo;
+  return gtkcairo;
 }
 
 static void
 gtk_cairo_destroy (GtkObject *object)
 {
-	GtkCairo *gtkcairo;
+  GtkCairo *gtkcairo;
 
-	g_return_if_fail (object != NULL);
-	g_return_if_fail (GTK_IS_CAIRO (object));
+  g_return_if_fail (object != NULL);
+  g_return_if_fail (GTK_IS_CAIRO (object));
 
-	gtkcairo = GTK_CAIRO (object);
+  gtkcairo = GTK_CAIRO (object);
 
-	gdkcairo_destroy (gtkcairo->gdkcairo);
+  gdkcairo_destroy (gtkcairo->gdkcairo);
 
-	if (GTK_OBJECT_CLASS (parent_class)->destroy)
-		(* GTK_OBJECT_CLASS (parent_class)->destroy) (object);
+  if (GTK_OBJECT_CLASS (parent_class)->destroy)
+    (*GTK_OBJECT_CLASS (parent_class)->destroy) (object);
 }
 
 static void
 gtk_cairo_realize (GtkWidget *widget)
 {
-	GtkCairo *gtkcairo;
+  GtkCairo *gtkcairo;
 
-	g_return_if_fail (widget != NULL);
-	g_return_if_fail (GTK_IS_CAIRO (widget));
+  g_return_if_fail (widget != NULL);
+  g_return_if_fail (GTK_IS_CAIRO (widget));
 
-	GTK_WIDGET_SET_FLAGS (widget, GTK_REALIZED);
-	gtkcairo = GTK_CAIRO (widget);
+  GTK_WIDGET_SET_FLAGS (widget, GTK_REALIZED);
+  gtkcairo = GTK_CAIRO (widget);
 
-	gdkcairo_realize (gtkcairo->gdkcairo);
+  gdkcairo_realize (gtkcairo->gdkcairo);
 }
 
 static void
 gtk_cairo_size_allocate (GtkWidget     *widget,
                          GtkAllocation *allocation)
 {
-    GtkCairo *gtkcairo;
-	g_return_if_fail (widget != NULL);
-	g_return_if_fail (GTK_IS_CAIRO (widget));
-	g_return_if_fail (allocation != NULL);
-
-	gtkcairo = GTK_CAIRO (widget);
-
-	widget->allocation = *allocation;
-
-	gdkcairo_size_allocate (gtkcairo->gdkcairo,
-			allocation->x, allocation->y,
-			allocation->width, allocation->height);
+  GtkCairo *gtkcairo;
+  g_return_if_fail (widget != NULL);
+  g_return_if_fail (GTK_IS_CAIRO (widget));
+  g_return_if_fail (allocation != NULL);
+
+  gtkcairo = GTK_CAIRO (widget);
+
+  widget->allocation = *allocation;
+
+  gdkcairo_size_allocate (gtkcairo->gdkcairo,
+                          allocation->x, allocation->y,
+                          allocation->width, allocation->height);
 }
 
 static gint
 gtk_cairo_expose (GtkWidget      *widget,
                   GdkEventExpose *event)
 {
-	GtkCairo *gtkcairo;
+  GtkCairo *gtkcairo;
 
-	g_return_val_if_fail (widget != NULL, FALSE);
-	g_return_val_if_fail (GTK_IS_CAIRO (widget), FALSE);
-	g_return_val_if_fail (event != NULL, FALSE);
+  g_return_val_if_fail (widget != NULL, FALSE);
+  g_return_val_if_fail (GTK_IS_CAIRO (widget), FALSE);
+  g_return_val_if_fail (event != NULL, FALSE);
 
-	gtkcairo = GTK_CAIRO (widget);
+  gtkcairo = GTK_CAIRO (widget);
 
-	cairo_save (gtk_cairo_get_cairo (gtkcairo));
-	gdkcairo_expose (gtkcairo->gdkcairo, event);
-	cairo_restore (gtk_cairo_get_cairo (gtkcairo));
-	return FALSE;
+  gdkcairo_expose (gtkcairo->gdkcairo, event);
+  return FALSE;
 }
 
-cairo_t *
-gtk_cairo_get_cairo (GtkCairo *gtkcairo) {
-	g_return_val_if_fail (gtkcairo != NULL, NULL);
-	g_return_val_if_fail (GTK_IS_CAIRO (gtkcairo), NULL);
-	return ((gdkcairo_t*) gtkcairo->gdkcairo)->cr;
+cairo_t  *
+gtk_cairo_get_cairo (GtkCairo *gtkcairo)
+{
+  g_return_val_if_fail (gtkcairo != NULL, NULL);
+  g_return_val_if_fail (GTK_IS_CAIRO (gtkcairo), NULL);
+  return ((gdkcairo_t *) gtkcairo->gdkcairo)->cr;
 }
 
 void
-gtk_cairo_set_gdk_color (cairo_t *cr,
+gtk_cairo_set_gdk_color (cairo_t  *cr,
                          GdkColor *color)
 {
-    double red, green, blue;
+  double    red, green, blue;
 
-    red   = color->red   / 65535.0;
-    green = color->green / 65535.0;
-    blue  = color->blue  / 65535.0;
+  red = color->red / 65535.0;
+  green = color->green / 65535.0;
+  blue = color->blue / 65535.0;
 
-    cairo_set_rgb_color (cr, red, green, blue);
+  cairo_set_source_rgb (cr, red, green, blue);
 }
 
 int
 gtk_cairo_backend_is_gl (GtkCairo *gtkcairo)
 {
-	if (((gdkcairo_t*)gtkcairo->gdkcairo)->backend == GDKCAIRO_BACKEND_GL)
-		return 1;
-	return 0;
+  if (((gdkcairo_t *) gtkcairo->gdkcairo)->backend == GDKCAIRO_BACKEND_GL)
+    return 1;
+  return 0;
 }
 
 #if 0
@@ -221,26 +215,25 @@
  */
 
 cairo_surface_t *
-gtk_cairo_surface_create_for_gdk_pixbuf (const GdkPixbuf *pixbuf)
+gtk_cairo_surface_create_for_gdk_pixbuf (const GdkPixbuf * pixbuf)
 {
-	cairo_surface_t *self;
-	char            *data;
-	cairo_format_t   format;
-	int              width;
-	int              height;
-	int              stride;
-
-	if (!pixbuf)
-		return NULL;
-	data   = gdk_pixbuf_get_pixels (pixbuf);
-	width  = gdk_pixbuf_get_width  (pixbuf);
-	height = gdk_pixbuf_get_height (pixbuf);
-	format = CAIRO_FORMAT_ARGB32;
-	stride = gdk_pixbuf_get_rowstride (pixbuf);
-
-	self   = cairo_surface_create_for_image (
-			    data, format, width, height, stride);
-	return self;
+  cairo_surface_t *self;
+  char     *data;
+  cairo_format_t format;
+  int       width;
+  int       height;
+  int       stride;
+
+  if (!pixbuf)
+    return NULL;
+  data = gdk_pixbuf_get_pixels (pixbuf);
+  width = gdk_pixbuf_get_width (pixbuf);
+  height = gdk_pixbuf_get_height (pixbuf);
+  format = CAIRO_FORMAT_ARGB32;
+  stride = gdk_pixbuf_get_rowstride (pixbuf);
+
+  self = cairo_surface_create_for_image (data, format, width, height, stride);
+  return self;
 }
 #endif
 
