--- src/cairo_glitz_surface.c.orig	Thu Jan 20 11:29:19 2005
+++ src/cairo_glitz_surface.c	Wed Feb 16 19:20:26 2005
@@ -333,7 +333,7 @@
     if (format == NULL)
 	return NULL;
     
-    surface = glitz_surface_create (drawable, format, 1, 1);
+    surface = glitz_surface_create (drawable, format, 1, 1, 0, NULL);
     if (surface == NULL)
 	return NULL;
 
@@ -355,7 +355,6 @@
 	glitz_drawable_format_t templ;
 	glitz_format_t *format;
 	glitz_drawable_t *pbuffer;
-	glitz_pbuffer_attributes_t attributes;
 	unsigned long mask;
 	int i;
 	
@@ -397,21 +396,13 @@
 	if (!dformat)
 	    return CAIRO_INT_STATUS_UNSUPPORTED;
 
-	attributes.width = glitz_surface_get_width (surface);
-	attributes.height = glitz_surface_get_height (surface);
-	mask = GLITZ_PBUFFER_WIDTH_MASK | GLITZ_PBUFFER_HEIGHT_MASK;
-
-	pbuffer = glitz_create_pbuffer_drawable (drawable, dformat,
-						 &attributes, mask);
+	pbuffer =
+	    glitz_create_pbuffer_drawable (drawable, dformat,
+					   glitz_surface_get_width (surface),
+					   glitz_surface_get_height (surface));
 	if (!pbuffer)
 	    return CAIRO_INT_STATUS_UNSUPPORTED;
 
-	if (glitz_drawable_get_width (pbuffer) < attributes.width ||
-	    glitz_drawable_get_height (pbuffer) < attributes.height) {
-	    glitz_drawable_destroy (pbuffer);
-	    return CAIRO_INT_STATUS_UNSUPPORTED;
-	}
-
 	glitz_surface_attach (surface, pbuffer,
 			      GLITZ_DRAWABLE_BUFFER_FRONT_COLOR,
 			      0, 0);
@@ -457,7 +448,7 @@
     if (gformat == NULL)
 	return NULL;
     
-    surface = glitz_surface_create (drawable, gformat, width, height);
+    surface = glitz_surface_create (drawable, gformat, width, height, 0, NULL);
     if (surface == NULL)
 	return NULL;
 
@@ -510,7 +501,8 @@
 		  int width,
 		  int height,
 		  glitz_buffer_t *geometry,
-		  glitz_geometry_format_t *format)
+		  glitz_geometry_format_t *format,
+		  int count)
 {
     if (_glitz_ensure_target (dst))
 	return CAIRO_INT_STATUS_UNSUPPORTED;
@@ -518,9 +510,10 @@
     if (glitz_surface_get_status (dst))
 	return CAIRO_STATUS_NO_TARGET_SURFACE;
 
-    glitz_set_geometry (dst,
-			0, 0,
-			format, geometry);
+    if (geometry) {
+	glitz_set_geometry (dst, GLITZ_GEOMETRY_TYPE_VERTEX, format, geometry);
+	glitz_set_array (dst, 0, 2, count, 0, 0);
+    }
 
     glitz_composite (op,
 		     src,
@@ -531,7 +524,7 @@
 		     dst_x, dst_y,
 		     width, height);
 
-    glitz_set_geometry (dst, 0, 0, NULL, NULL);
+    glitz_set_geometry (dst, GLITZ_GEOMETRY_TYPE_NONE, NULL, NULL);
 
     if (glitz_surface_get_status (dst) == GLITZ_STATUS_NOT_SUPPORTED)
 	return CAIRO_INT_STATUS_UNSUPPORTED;
@@ -589,7 +582,7 @@
 			       mask_x, mask_y,
 			       dst_x, dst_y,
 			       width, height,
-			       NULL, NULL);
+			       NULL, NULL, 0);
 
     if (src_clone)
 	cairo_surface_destroy (&src_clone->base);
@@ -624,16 +617,16 @@
 	glitz_buffer_t *buffer;
 	glitz_geometry_format_t gf;
 	cairo_int_status_t status;
-	int width, height;
+	int width, height, count;
 	void *data;
 	
-	gf.mode = GLITZ_GEOMETRY_MODE_DIRECT;
-	gf.edge_hint = GLITZ_GEOMETRY_EDGE_HINT_SHARP;
-	gf.primitive = GLITZ_GEOMETRY_PRIMITIVE_QUADS;
-	gf.type = GLITZ_DATA_TYPE_FLOAT;
-	gf.first = 0;
-	gf.count = n_rects * 4;
+	gf.vertex.primitive = GLITZ_PRIMITIVE_QUADS;
+	gf.vertex.type = GLITZ_DATA_TYPE_FLOAT;
+	gf.vertex.bytes_per_vertex = 2 * sizeof (glitz_float_t);
+	gf.vertex.attributes = 0;
 
+	count = n_rects * 4;
+	
 	data = malloc (n_rects * 8 * sizeof (glitz_float_t));
 	if (!data)
 	    return CAIRO_STATUS_NO_MEMORY;
@@ -678,7 +671,7 @@
 				   0, 0,
 				   0, 0,
 				   width, height,
-				   buffer, &gf);
+				   buffer, &gf, count);
 
 	glitz_surface_destroy (solid);
 	glitz_buffer_destroy (buffer);
@@ -715,7 +708,7 @@
     glitz_buffer_t *buffer;
     glitz_geometry_format_t gf;
     cairo_int_status_t status;
-    int x_dst, y_dst, x_rel, y_rel, width, height;
+    int x_dst, y_dst, x_rel, y_rel, width, height, count;
     void *data;
 
     if (op == CAIRO_OPERATOR_SATURATE)
@@ -724,12 +717,12 @@
     if (generic_src->backend != dst->base.backend)
 	return CAIRO_INT_STATUS_UNSUPPORTED;
 
-    gf.mode = GLITZ_GEOMETRY_MODE_DIRECT;
-    gf.edge_hint = GLITZ_GEOMETRY_EDGE_HINT_GOOD_SMOOTH;
-    gf.primitive = GLITZ_GEOMETRY_PRIMITIVE_QUADS;
-    gf.type = GLITZ_DATA_TYPE_FLOAT;
-    gf.first = 0;
-    gf.count = n_traps * 4;
+    gf.vertex.primitive = GLITZ_PRIMITIVE_QUADS;
+    gf.vertex.type = GLITZ_DATA_TYPE_FLOAT;
+    gf.vertex.bytes_per_vertex = 2 * sizeof (glitz_float_t);
+    gf.vertex.attributes = 0;
+
+    count = n_traps * 4;
 
     data = malloc (n_traps * 8 * sizeof (glitz_float_t));
     if (!data)
@@ -795,7 +788,7 @@
 			       0, 0,
 			       x_dst, y_dst,
 			       width, height,
-			       buffer, &gf);
+			       buffer, &gf, count);
 
     if (mask)
 	glitz_surface_destroy (mask);
