
$FreeBSD$

--- lib/charconv.c	2002/06/03 07:54:31	1.1
+++ lib/charconv.c	2002/06/03 08:10:29
@@ -98,7 +98,8 @@
 
       if ((*charset == NULL) ||
           (0==strcmp(*charset,"US-ASCII")) ||
-          (0==strcmp(*charset,"ANSI_X3.4-1968"))) {
+          (0==strcmp(*charset,"ANSI_X3.4-1968")) ||
+          (**charset == '\0')) {
               /* we got basic stupid ASCII here. We use its sane
                  superset instead. Especially since libxml2 doesn't like
                  the pedantic name of ASCII. */
