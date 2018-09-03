--- lib/src/pcap.c.orig	2018-09-03 16:11:24 UTC
+++ lib/src/pcap.c
@@ -110,7 +110,7 @@ typedef struct {
 	pcap_bluetooth_bredr_bb_header bredr_bb_header;
 } pcap_bredr_packet;
 
-void btbb_pcap_dump(FILE *file, pcaprec_hdr_t *pcap_header, u_char *data) {
+void btbb_pcap_dump(FILE *file, pcaprec_hdr_t *pcap_header, char *data) {
 	fwrite(pcap_header, sizeof(*pcap_header), 1, file);
 	fwrite(data, pcap_header->incl_len, 1, file);
 	fflush(file);
@@ -202,7 +202,7 @@ btbb_pcap_append_packet(btbb_pcap_handle * h, const ui
 					      btbb_packet_get_header_packed(pkt),
 					      flags,
 					      payload_bytes );
-		btbb_pcap_dump(h->pcap_file, &pcap_pkt.pcap_header, (u_char *)&pcap_pkt.bredr_bb_header);
+		btbb_pcap_dump(h->pcap_file, &pcap_pkt.pcap_header, (char *)&pcap_pkt.bredr_bb_header);
 		return 0;
 	}
 	return -PCAP_INVALID_HANDLE;
@@ -331,7 +331,7 @@ lell_pcap_append_packet(lell_pcap_handle * h, const ui
 					   refAA,
 					   flags,
 					   &pkt->symbols[0] );
-		btbb_pcap_dump(h->pcap_file, &pcap_pkt.pcap_header, (u_char *)&pcap_pkt.le_ll_header);
+		btbb_pcap_dump(h->pcap_file, &pcap_pkt.pcap_header, (char *)&pcap_pkt.le_ll_header);
 		return 0;
 	}
 	return -PCAP_INVALID_HANDLE;
@@ -410,7 +410,7 @@ lell_pcap_append_ppi_packet(lell_pcap_handle * h, cons
 		pcap_pkt.le_ll_ppi_header.rssi_avg = rssi_avg;
 		pcap_pkt.le_ll_ppi_header.rssi_count = rssi_count;
 		(void) memcpy( &pcap_pkt.le_packet[0], &pkt->symbols[0], incl_len);
-		btbb_pcap_dump(h->pcap_file, &pcap_pkt.pcap_header, (u_char *)&pcap_pkt.ppi_packet_header);
+		btbb_pcap_dump(h->pcap_file, &pcap_pkt.pcap_header, (char *)&pcap_pkt.ppi_packet_header);
 		return 0;
 	}
 	return -PCAP_INVALID_HANDLE;
