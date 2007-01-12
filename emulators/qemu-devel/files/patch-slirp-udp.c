Index: qemu/slirp/udp.c
@@ -205,8 +208,6 @@
 	  /* udp_last_so = so; */
 	  so->so_laddr = ip->ip_src;
 	  so->so_lport = uh->uh_sport;
-	  so->so_faddr = ip->ip_dst; /* XXX */
-	  so->so_fport = uh->uh_dport; /* XXX */
 	  
 	  if ((so->so_iptos = udp_tos(so)) == 0)
 	    so->so_iptos = ip->ip_tos;
@@ -216,6 +217,15 @@
 	   * and if it is, do the fork_exec() etc.
 	   */
 	}
+
+	/*
+	 * Assign destination unconditionally
+	 *
+	 * This fixes the case where packets are sent from the same
+	 * source ip/port to different destination ips/ports
+	 */
+	so->so_faddr = ip->ip_dst; /* XXX */
+	so->so_fport = uh->uh_dport; /* XXX */
 
 	iphlen += sizeof(struct udphdr);
 	m->m_len -= iphlen;
