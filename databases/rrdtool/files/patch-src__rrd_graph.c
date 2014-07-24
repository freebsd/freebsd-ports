--- src/rrd_graph.c.orig	2013-05-23 09:55:07.000000000 +0200
+++ src/rrd_graph.c	2014-07-20 22:11:58.000000000 +0200
@@ -305,6 +305,52 @@
 
 #undef conv_if
 
+
+static int bad_format_imginfo(
+    char *fmt)
+{
+    char     *ptr;
+    int       n = 0;
+
+    ptr = fmt;
+    while (*ptr != '\0')
+        if (*ptr++ == '%') {
+
+            /* line cannot end with percent char */
+            if (*ptr == '\0')
+                return 1;
+            /* '%%' is allowed */
+            if (*ptr == '%')
+                ptr++;
+            /* '%s', '%S' are allowed */
+            else if (*ptr == 's' || *ptr == 'S') {
+                n = 1;
+                ptr++;
+            }
+
+            /* or else '% 4lu' and such are allowed */
+            else {
+                /* optional padding character */
+                if (*ptr == ' ')
+                    ptr++;
+                /* This should take care of 'm' */
+                while (*ptr >= '0' && *ptr <= '9')
+                    ptr++;
+                /* 'lu' must follow here */
+                if (*ptr++ != 'l')
+                    return 1;
+                if (*ptr == 'u')
+                    ptr++;
+                else
+                    return 1;
+                n++;
+            }
+        }
+
+    return (n != 3);
+}
+
+
 int im_free(
     image_desc_t *im)
 {
@@ -4022,6 +4068,12 @@
         char     *path;
         char     *filename;
 
+        if (bad_format_imginfo(im.imginfo)) {
+            rrd_info_free(im.grinfo);
+            im_free(&im);
+            rrd_set_error("bad format for imginfo");
+            return NULL;
+        }
         path = strdup(im.graphfile);
         filename = basename(path);
         info.u_str =
