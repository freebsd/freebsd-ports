--- src/misc.c.orig	Sat Sep 10 11:30:49 2005
+++ src/misc.c	Sat Oct  8 00:12:35 2005
@@ -319,9 +319,9 @@
 misc_parse_expression(const gchar *s, gint *result)
 {
    gint value = 0;
+   gint loop = 1;
    s = misc_parse_value(s, &value);
    *result = value;
-   gint loop = 1;
    while (loop) {
       s = misc_skip_spaces(s);
       switch(*s) {
