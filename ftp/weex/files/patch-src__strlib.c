--- ./src/strlib.c.orig	2013-04-02 14:27:50.088885186 +0200
+++ ./src/strlib.c	2013-04-02 14:29:17.656194116 +0200
@@ -42,6 +42,8 @@
 #  define G_VA_COPY(ap1, ap2)     (*(ap1) = *(ap2))
 #  elif defined (G_VA_COPY_AS_ARRAY)
 #  define G_VA_COPY(ap1, ap2)     g_memmove ((ap1), (ap2), sizeof (va_list))
+#  elif defined (__x86_64__)
+#  define G_VA_COPY(ap1, ap2)     memmove ((ap1), (ap2), sizeof (va_list))
 #  else /* va_list is a pointer */
 #  define G_VA_COPY(ap1, ap2)     ((ap1) = (ap2))
 #  endif /* va_list is a pointer */
