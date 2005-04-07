$FreeBSD$

--- src/gx.h.orig	Fri Mar 25 15:37:16 2005
+++ src/gx.h	Fri Mar 25 15:37:53 2005
@@ -45,7 +45,7 @@
 /* Default directory containing the stroke and map data sets.
    User can override this default via setenv GADDIR */
 
-static char *datad = "/usr/local/lib/grads";
+static char *datad = "%%DATADIR%%";
 
 /* Option flag.  If 0, map data set is only read once into a
    dynamically allocated memory area.  The memory is held onto
