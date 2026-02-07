Fix build with Qt5 5.13, which defined GLsizeiptr already.

Obtained from:
	https://www.mail-archive.com/pld-cvs-commit@lists.pld-linux.org/msg436220.html

--- include/VBox/VBoxGL2D.h.orig	2019-09-29 14:31:16 UTC
+++ include/VBox/VBoxGL2D.h
@@ -107,7 +107,7 @@ typedef GLvoid (APIENTRY *PFNVBOXVHWA_UNIFORM3I)(GLint
 typedef GLvoid (APIENTRY *PFNVBOXVHWA_UNIFORM4I)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
 
 /* GL_ARB_pixel_buffer_object*/
-#ifndef Q_WS_MAC
+#if 0
 /* apears to be defined on mac */
 typedef ptrdiff_t GLsizeiptr;
 #endif
