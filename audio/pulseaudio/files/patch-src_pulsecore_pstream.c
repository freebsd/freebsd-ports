--- src/pulsecore/pstream.c.orig	2007-10-28 15:13:53.000000000 -0400
+++ src/pulsecore/pstream.c	2008-01-01 16:14:18.000000000 -0500
@@ -183,14 +183,17 @@ static void do_something(pa_pstream *p) 
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
 
     if (!p->dead && pa_iochannel_is_writable(p->io)) {
-        if (do_write(p) < 0)
+        if (do_write(p) < 0) {
             goto fail;
+	}
     }
 
     pa_pstream_unref(p);
