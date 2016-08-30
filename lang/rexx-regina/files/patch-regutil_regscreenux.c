--- regutil/regscreenux.c.orig	2012-08-08 01:23:45 UTC
+++ regutil/regscreenux.c
@@ -21,6 +21,8 @@
  * $Header: /opt/cvs/Regina/regutil/regscreenux.c,v 1.9 2012/08/08 01:23:45 mark Exp $
  */
 #include "regutil.h"
+#include </usr/include/strings.h>
+
 #ifdef USE_TERMCAP_DB
 # ifdef HAVE_NCURSES_H
 #  include <ncurses.h>
@@ -91,7 +93,7 @@ rxfunc(syscls)
 
    if (!*clr) {
       sethandles();
-      clr = tgetstr("cl", &clrbuf);
+      clr = tgetstr("cl", (char **) &clrbuf);
    }
 #else
    /* ansi terminal control for clearing the screen should work with any
@@ -128,7 +130,7 @@ rxfunc(syscurpos)
 #ifdef USE_TERMCAP_DB
    if (!*cpos) {
       sethandles();
-      cpos = tgetstr("cm", &cposbuf);
+      cpos = tgetstr("cm", (char **) &cposbuf);
    }
 #endif
 
@@ -179,8 +181,8 @@ rxfunc(syscurstate)
    if (!*css) {
       char *pcss = css;
       sethandles();
-      pcsson = tgetstr("ve", &css);
-      pcssoff = tgetstr("vi", &css);
+      pcsson = tgetstr("ve", (char **) &css);
+      pcssoff = tgetstr("vi", (char **) &css);
    }
 #endif
 
