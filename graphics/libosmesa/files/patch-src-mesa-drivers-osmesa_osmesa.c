--- src/mesa/drivers/osmesa/osmesa.c.orig	2010-07-22 15:04:03.000000000 +0200
+++ src/mesa/drivers/osmesa/osmesa.c	2010-07-22 15:04:02.000000000 +0200
@@ -1329,6 +1329,7 @@
     * size.
     */
    osmesa->rb = new_osmesa_renderbuffer(&osmesa->mesa, osmesa->format, type);
+   _mesa_remove_renderbuffer(osmesa->gl_buffer, BUFFER_FRONT_LEFT);
    _mesa_add_renderbuffer(osmesa->gl_buffer, BUFFER_FRONT_LEFT, osmesa->rb);
    assert(osmesa->rb->RefCount == 2);
 
