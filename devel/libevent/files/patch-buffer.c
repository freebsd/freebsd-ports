#
# Define va_copy if not exists. 4.x for exemple.
#
--- buffer.c.orig	Mon Dec  4 11:34:31 2006
+++ buffer.c	Mon Dec  4 11:35:44 2006
@@ -138,6 +138,9 @@
 		buffer = (char *)buf->buffer + buf->off;
 		space = buf->totallen - buf->misalign - buf->off;
 
+#ifndef va_copy
+#define	va_copy(dest,src)	memcpy(&dest, &src, sizeof (va_list))
+#endif
 		va_copy(aq, ap);
 
 #ifdef WIN32
