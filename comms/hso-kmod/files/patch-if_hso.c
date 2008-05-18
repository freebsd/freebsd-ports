--- if_hso.c.orig	2008-05-18 15:16:15.402471749 +0200
+++ if_hso.c	2008-05-18 15:16:54.689656014 +0200
@@ -831,7 +831,7 @@
 
 	ht = tp->t_sc;
 	if (cnt > ht->ht_obufsz) {
-		DPRINTF(1, "too many bytes %d, reducing to %d\n",
+		DPRINTF(1, "too many bytes %d, reducing to %zd\n",
 		    cnt, ht->ht_obufsz);
 		cnt = ht->ht_obufsz;
 	}
@@ -1005,7 +1005,7 @@
 	len = m->m_pkthdr.len - ETHER_HDR_LEN;
 	m_copydata(m, ETHER_HDR_LEN, len, ib->ib_buf);
 
-	DPRINTF(5, "hso_if_start: mlen=%d, len=%d\n",
+	DPRINTF(5, "hso_if_start: mlen=%d, len=%zd\n",
 	    m->m_pkthdr.len, len);
 
 	m_freem(m);
