--- comps/ftp.c.orig	2007-11-23 23:37:24.000000000 +0100
+++ comps/ftp.c	2007-11-23 23:41:03.000000000 +0100
@@ -554,7 +554,7 @@
  /* Schedule next computation */
   ev_enqueue(EV_INSTANT_RATE,  (Component *)g, (Component *)g,
 	    ev_now() + perf_update_dt_usecs / USECS_PER_TICK,
-             g->ftp_action, (caddr_t *)NULL, (caddr_t)NULL);
+             g->ftp_action, (Packet *)NULL, (caddr_t)NULL);
   return ((caddr_t)g);
 }
 
@@ -584,7 +584,7 @@
   /* Schedule first computation of instantaneous thruput */
   ev_enqueue(EV_INSTANT_RATE,  (Component *)g, (Component *)g, 
 	     ev_now() + perf_update_dt_usecs/USECS_PER_TICK,
-             g->ftp_action, (caddr_t *)NULL, (caddr_t)NULL);
+             g->ftp_action, (Packet *)NULL, (caddr_t)NULL);
 
   /* produce first packet */
   if (strcmp(g->init_conn_on_off->u.p, "On") == 0)
@@ -593,7 +593,7 @@
      time = ticks_btw_conns(g);
 
    ev_enqueue(EV_APTR_CONN_ON, (Component *)g, (Component *)g, 
-	      time, g->ftp_action, (caddr_t *)NULL, train_length(g));
+	      time, g->ftp_action, (Packet *)NULL, (caddr_t)train_length(g));
  
   /* send a token packet */
   pkt = pk_alloc();
@@ -707,7 +707,7 @@
      /* schedule an event for the next pkt */
      ev_enqueue(EV_APTR_PRODUCE, (Component *)g, (Component *)g, 
 		ev_now() + ticks_btw_packets(g),
-		g->ftp_action, (caddr_t *)NULL, (caddr_t)NULL);
+		(PFP)g->ftp_action, (Packet *)NULL, (caddr_t)NULL);
   else {
      g->produce_scheduled = 0;
      /* schedule an event for the next connection i.e. train */
@@ -715,7 +715,7 @@
 	 g->ftp_tr_how_many->u.i == -1) 
 	ev_enqueue(EV_APTR_CONN_ON, (Component *)g, (Component *)g, 
 		   ev_now() + ticks_btw_conns(g),
-		   g->ftp_action, (Packet *)NULL, train_length(g));
+		   g->ftp_action, (Packet *)NULL, (caddr_t) train_length(g));
   }
   
   return((caddr_t)g);
