
$FreeBSD$

--- erts/emulator/drivers/common/inet_drv.c.orig
+++ erts/emulator/drivers/common/inet_drv.c
@@ -5684,7 +5684,11 @@
 	    arg.es.sctp_peer_error_event       = get_int8(curr);   curr++;
 	    arg.es.sctp_shutdown_event	       = get_int8(curr);   curr++;
 	    arg.es.sctp_partial_delivery_event = get_int8(curr);   curr++;
+#	    ifdef HAVE_STRUCT_SCTP_EVENT_SUBSCRIBE_SCTP_ADAPTATION_LAYER_EVENT
+	    arg.es.sctp_adaptation_layer_event = get_int8(curr);   curr++;
+#	    else
 	    arg.es.sctp_adaption_layer_event   = get_int8(curr);   curr++;
+#	    endif
 
 	    proto   = IPPROTO_SCTP;
 	    type    = SCTP_EVENTS;
@@ -6580,7 +6584,11 @@
 	    i = LOAD_BOOL	(spec, i, evs.sctp_peer_error_event);
 	    i = LOAD_BOOL	(spec, i, evs.sctp_shutdown_event);
 	    i = LOAD_BOOL	(spec, i, evs.sctp_partial_delivery_event);
+#	    ifdef HAVE_STRUCT_SCTP_EVENT_SUBSCRIBE_SCTP_ADAPTATION_LAYER_EVENT
+	    i = LOAD_BOOL	(spec, i, evs.sctp_adaptation_layer_event);
+#	    else
 	    i = LOAD_BOOL	(spec, i, evs.sctp_adaption_layer_event);
+#	    endif
 	    /* NB: sctp_authentication_event is not yet supported in Linux */
 	    i = LOAD_TUPLE	(spec, i, 9);
 	    i = LOAD_TUPLE	(spec, i, 2);
