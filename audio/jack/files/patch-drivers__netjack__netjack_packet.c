--- ./drivers/netjack/netjack_packet.c.orig	2009-11-12 22:09:39.000000000 +0100
+++ ./drivers/netjack/netjack_packet.c	2011-04-12 11:31:54.221162522 +0200
@@ -1427,9 +1427,9 @@
 
 	    CELTDecoder *decoder = src_node->data;
 	    if( !packet_payload )
-		celt_decode_float( decoder, NULL, net_period_down, buf );
+		celt_decode_float( decoder, NULL, net_period_down, buf, 1);
 	    else
-		celt_decode_float( decoder, packet_bufX, net_period_down, buf );
+		celt_decode_float( decoder, packet_bufX, net_period_down, buf, 1);
 
 	    src_node = jack_slist_next (src_node);
         }
@@ -1471,7 +1471,7 @@
 	    float *floatbuf = alloca (sizeof(float) * nframes );
 	    memcpy( floatbuf, buf, nframes*sizeof(float) );
 	    CELTEncoder *encoder = src_node->data;
-	    encoded_bytes = celt_encode_float( encoder, floatbuf, NULL, packet_bufX, net_period_up );
+	    encoded_bytes = celt_encode_float( encoder, floatbuf, 1, packet_bufX, net_period_up );
 	    if( encoded_bytes != net_period_up )
 		printf( "something in celt changed. netjack needs to be changed to handle this.\n" );
 	    src_node = jack_slist_next( src_node );
