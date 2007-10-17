--- src/net.c.orig	2007-10-02 13:33:00.000000000 +0200
+++ src/net.c	2007-10-02 13:33:28.000000000 +0200
@@ -459,7 +459,7 @@
     return 0;
   }
   
-  l = &(buff == SB_IN ? s->in_buff_last : s->out_buff_last);
+  l = (buff == SB_IN ? &(s->in_buff_last) : &(s->out_buff_last));
 
   /* Check whether we can just add to the existing buffer */
   if ((mode == SM_RAW) && *l && ((*l)->mode == mode)) {
