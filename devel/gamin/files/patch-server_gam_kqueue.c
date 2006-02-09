--- server/gam_kqueue.c.orig	Wed Aug 10 23:50:32 2005
+++ server/gam_kqueue.c	Wed Feb  8 12:43:52 2006
@@ -10,9 +10,8 @@
  *       FAM should do: we do not call g_dir_open() if the file is a
  *       symbolic link).
  *
- *     * kqueue cannot monitor files residing on anything but a UFS
- *       file system. If kqueue cannot monitor a file, this backend
- *       will poll it periodically.
+ *     * kqueue can only monitor files residing on a UFS file system.
+ *       For other file systems, the basic poll backend will be used.
  *
  *     * Monitoring a file with kqueue prevents the file system it
  *       resides on from being unmounted, because kqueue can only
@@ -31,7 +30,8 @@
  *           - kqueue needs to be moved out the UFS code.
  *
  * Copyright (C) 2005 Joe Marcus Clarke <marcus@FreeBSD.org>
- * Copyright (C) 2005 Jean-Yves Lefort <jylefort@FreeBSD.org>
+ * Copyright (C) 2005, 2006 Jean-Yves Lefort <jylefort@FreeBSD.org>
+ * Copyright (C) 2006 Alex Dupre <ale@FreeBSD.org>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Lesser General Public
@@ -63,7 +63,7 @@
 #include "gam_kqueue.h"
 #include "gam_event.h"
 #include "gam_server.h"
-#include "gam_poll.h"
+#include "gam_poll_basic.h"
 
 /*** tunable constants, modify to tweak the backend aggressivity *************/
 
@@ -516,7 +516,7 @@
       return FALSE;
     }
   
-  mon->fd = open(mon->pathname, O_RDONLY | O_NOFOLLOW);
+  mon->fd = open(mon->pathname, O_RDONLY | O_NONBLOCK | O_NOFOLLOW);
   if (mon->fd < 0)
     {
       GAM_DEBUG(DEBUG_INFO, "cannot open %s (%s), falling back to poll\n", mon->pathname, g_strerror(errno));
@@ -840,6 +840,8 @@
     case GAMIN_EVENT_MOVED:
       gam_kqueue_sub_monitor_set_missing(smon);
       break;
+    default:
+      break;
     }
 
   gam_server_emit_event(mon->pathname, isdir, event, smon->subs, 1);
@@ -981,6 +983,8 @@
 	
       gam_kqueue_hash_table_remove(fmon->smon->fmons, fmon);
       break;
+    default:
+      break;
     }
 }
 
@@ -1167,11 +1171,13 @@
   channel = g_io_channel_unix_new(kq);
   g_io_add_watch(channel, G_IO_IN, gam_kqueue_kevent_cb, NULL);
 
-  
-  gam_poll_set_kernel_handler(NULL, NULL, GAMIN_K_KQUEUE);
-  gam_backend_add_subscription = gam_kqueue_add_subscription;
-  gam_backend_remove_subscription = gam_kqueue_remove_subscription;
-  gam_backend_remove_all_for = gam_kqueue_remove_all_for;
+  gam_poll_basic_init (); 
+  gam_server_install_kernel_hooks (GAMIN_K_KQUEUE,
+                                   gam_kqueue_add_subscription,
+                                   gam_kqueue_remove_subscription,
+                                   gam_kqueue_remove_all_for,
+                                   NULL,
+                                   NULL);
 
   return TRUE;
 }
