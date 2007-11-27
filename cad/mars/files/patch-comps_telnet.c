--- comps/telnet.c.orig	2007-11-23 23:41:45.000000000 +0100
+++ comps/telnet.c	2007-11-23 23:42:14.000000000 +0100
@@ -619,7 +619,7 @@
      time = ticks_btw_conns(g);
 
    ev_enqueue(EV_APTR_CONN_ON, (Component *)g, (Component *)g, 
-	      time, g->telnet_action, (Packet *)NULL, train_length(g));
+	      time, g->telnet_action, (Packet *)NULL, (caddr_t)train_length(g));
 
   /* send a token packet */
   pkt = pk_alloc();
@@ -760,7 +760,7 @@
          g->telnet_tr_how_many->u.i == -1)
 	ev_enqueue(EV_APTR_CONN_ON, (Component *)g, (Component *)g, 
 		   ev_now() + ticks_btw_conns(g),
-		   g->telnet_action, (Packet *)NULL, train_length(g));
+		   g->telnet_action, (Packet *)NULL, (caddr_t)train_length(g));
   }
 
   return((caddr_t)g);
