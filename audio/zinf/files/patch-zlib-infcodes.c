--- lib/zlib/src/infcodes.c.orig	Thu Jun 20 08:40:24 2002
+++ lib/zlib/src/infcodes.c	Sun Aug  4 16:45:11 2002
@@ -197,8 +197,18 @@
       c->mode = COPY;
     case COPY:          /* o: copying bytes in window, waiting for space */
       f = q - c->sub.copy.dist;
+#ifdef __FreeBSD__
+      {
+      /* Work-around for a FreeBSD gcc bug. */
+      volatile inflate_blocks_statef *s1 = s;
+
+      while (f < s1->window)            /* modulo window size-"while" instead */
+        f += s1->end - s1->window;      /* of "if" handles invalid distances */
+      }
+#else
       while (f < s->window)             /* modulo window size-"while" instead */
         f += s->end - s->window;        /* of "if" handles invalid distances */
+#endif
       while (c->len)
       {
         NEEDOUT
