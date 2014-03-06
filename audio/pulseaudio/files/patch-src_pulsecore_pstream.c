--- src/pulsecore/pstream.c.orig	2014-01-23 13:57:55.000000000 -0500
+++ src/pulsecore/pstream.c	2014-03-06 09:42:44.754769964 -0500
@@ -182,15 +182,18 @@
     p->mainloop->defer_enable(p->defer_event, 0);
 
     if (!p->dead && pa_iochannel_is_readable(p->io)) {
-        if (do_read(p) < 0)
+        if (do_read(p) < 0) {
             goto fail;
-    } else if (!p->dead && pa_iochannel_is_hungup(p->io))
+	}
+    } else if (!p->dead && pa_iochannel_is_hungup(p->io)) {
         goto fail;
+    }
 
     while (!p->dead && pa_iochannel_is_writable(p->io)) {
         int r = do_write(p);
-        if (r < 0)
+        if (r < 0) {
             goto fail;
+	}
         if (r == 0)
             break;
     }
