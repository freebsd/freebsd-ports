--- server/gam_kqueue.c.orig	Mon Feb  6 18:00:49 2006
+++ server/gam_kqueue.c	Mon Feb  6 18:01:25 2006
@@ -31,7 +31,7 @@
  *           - kqueue needs to be moved out the UFS code.
  *
  * Copyright (C) 2005 Joe Marcus Clarke <marcus@FreeBSD.org>
- * Copyright (C) 2005 Jean-Yves Lefort <jylefort@FreeBSD.org>
+ * Copyright (C) 2005, 2006 Jean-Yves Lefort <jylefort@FreeBSD.org>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Lesser General Public
@@ -515,7 +515,7 @@
       return FALSE;
     }
   
-  mon->fd = open(mon->pathname, O_RDONLY | O_NOFOLLOW);
+  mon->fd = open(mon->pathname, O_RDONLY | O_NONBLOCK | O_NOFOLLOW);
   if (mon->fd < 0)
     {
       GAM_DEBUG(DEBUG_INFO, "cannot open %s (%s), falling back to poll\n", mon->pathname, g_strerror(errno));
