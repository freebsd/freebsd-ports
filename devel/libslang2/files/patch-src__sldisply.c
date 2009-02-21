--- src/sldisply.c~	2008-08-24 20:14:47.000000000 -0400
+++ src/sldisply.c	2009-02-19 09:59:08.000000000 -0500
@@ -2233,10 +2233,9 @@
     * this more general.
     */
    /* FIXME: Priority=low; */
-   if (0 == strcmp (cap, "ac"))
-     return s;
+   if (0 != strcmp (cap, "ac"))
+     s = fixup_tgetstr (s);
 
-   s = fixup_tgetstr (s);
 #ifdef USE_TERMCAP
    if ((s >= area_buf) && (s < area_buf + sizeof(area_buf)))
      {
