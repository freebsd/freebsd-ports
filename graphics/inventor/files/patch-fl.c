*** libFL/ang/fl.c.orig	Thu Jan  2 16:28:23 2003
--- libFL/ang/fl.c	Thu Jan  2 16:32:25 2003
***************
*** 95,101 ****
--- 95,105 ----
    NULL
  };
  
+ #ifdef __FreeBSD__
+ static char *fontPath = IVPREFIX "/lib/X11/fonts/TTF";
+ #else
  static char *fontPath = IVPREFIX "/share/data/fonts";
+ #endif
  int fl_debug = FALSE;
  
  /*
