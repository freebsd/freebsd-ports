--- src/pulsecore/pstream.c.orig	Wed Jul 11 23:57:46 2007
+++ src/pulsecore/pstream.c	Wed Jul 11 23:57:49 2007
@@ -178,14 +178,17 @@ static void do_something(pa_pstream *p) 
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
 
     pa_mutex_unlock(p->mutex);
@@ -197,12 +200,13 @@ fail:
 
     p->dead = 1;
 
-    if (p->die_callback)
+    if (p->die_callback) {
+        pa_mutex_unlock(p->mutex);
         p->die_callback(p, p->die_callback_userdata);
-
-    pa_mutex_unlock(p->mutex);
-
-    pa_pstream_unref(p);
+    } else {
+        pa_mutex_unlock(p->mutex);
+        pa_pstream_unref(p);
+    }
 }
 
 static void io_callback(pa_iochannel*io, void *userdata) {
