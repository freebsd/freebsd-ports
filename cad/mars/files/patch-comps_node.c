--- comps/node.c.orig	2007-11-23 23:35:05.000000000 +0100
+++ comps/node.c	2007-11-23 23:36:22.000000000 +0100
@@ -644,7 +644,7 @@
                                  nd->nd_delay->u.i/USECS_PER_TICK + ticks;
 	 ev_enqueue(EV_NODE_SEND, (Component *)nd, (Component *)nd,
 		   pkt->pk_time , nd->nd_action, (Packet *)NULL,
-		   (Neighbor *)n);
+		   (caddr_t)n);
       }
 
 
@@ -759,7 +759,7 @@
      pkt->pk_time = ev_now() + process_delay + ticks;
      ev_enqueue(EV_NODE_SEND, (Component *)nd, (Component *)nd,
 		pkt->pk_time , nd->nd_action, (Packet *)NULL,
-		(Neighbor *)n);
+		(caddr_t)n);
      q_addt(n->n_pq, (caddr_t)pkt);
      log_param((Component *)nd, n->n_p);
   }
@@ -804,7 +804,7 @@
   if (n->n_pq->q_len > 0) {
      time_value = ((Packet *)(n->n_pq->q_head->qe_data))->pk_time;
      ev_enqueue(EV_NODE_SEND, (Component *)nd, (Component *)nd,
-                time_value, nd->nd_action, (Packet *)NULL, (Neighbor *)n);
+                time_value, nd->nd_action, (Packet *)NULL, (caddr_t)n);
   }
   return((caddr_t)nd);
 }
