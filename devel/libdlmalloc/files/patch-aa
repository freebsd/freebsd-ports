--- malloc-2.8.6.c.orig	2009-10-24 20:31:13.000000000 -0200
+++ malloc-2.8.6.c	2009-10-24 20:33:30.000000000 -0200
@@ -1391,7 +1391,7 @@
 #  ifdef _SC_PAGE_SIZE
 #    define malloc_getpagesize sysconf(_SC_PAGE_SIZE)
 #  else
-#    if defined(BSD) || defined(DGUX) || defined(HAVE_GETPAGESIZE)
+#    if (defined(BSD) && (BSD < 199306)) || defined(DGUX) || defined(HAVE_GETPAGESIZE)
        extern size_t getpagesize();
 #      define malloc_getpagesize getpagesize()
 #    else
