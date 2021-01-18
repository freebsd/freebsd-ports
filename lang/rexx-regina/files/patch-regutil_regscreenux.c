--- regutil/regscreenux.c.orig	2019-10-06 06:19:40 UTC
+++ regutil/regscreenux.c
@@ -21,6 +21,9 @@
  * $Header: /opt/cvs/Regina/regutil/regscreenux.c,v 1.10 2016/01/20 00:07:46 mark Exp $
  */
 #include "regutil.h"
+
+#include </usr/include/strings.h>
+
 #ifdef USE_TERMCAP_DB
 # ifdef HAVE_NCURSES_H
 #  include <ncurses.h>
