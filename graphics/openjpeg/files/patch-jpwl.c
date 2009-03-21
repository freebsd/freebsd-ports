--- jpwl/jpwl.c.orig	2007-11-29 15:38:26.000000000 +0100
+++ jpwl/jpwl.c	2009-03-21 12:36:53.000000000 +0100
@@ -122,19 +122,19 @@
 		switch (jwmarker[mm].id) {
 
 		case J2K_MS_EPB:
-			free(jwmarker[mm].epbmark);
+			opj_aligned_free(jwmarker[mm].u.epbmark);
 			break;
 
 		case J2K_MS_EPC:
-			free(jwmarker[mm].epcmark);
+			opj_aligned_free(jwmarker[mm].u.epcmark);
 			break;
 
 		case J2K_MS_ESD:
-			free(jwmarker[mm].esdmark);
+			opj_aligned_free(jwmarker[mm].u.esdmark);
 			break;
 
 		case J2K_MS_RED:
-			free(jwmarker[mm].redmark);
+			opj_aligned_free(jwmarker[mm].u.redmark);
 			break;
 
 		default:
@@ -213,7 +213,7 @@
 		/* Add this marker to the 'insertanda' list */
 		if (epc_mark) {
 			jwmarker[jwmarker_num].id = J2K_MS_EPC; /* its type */
-			jwmarker[jwmarker_num].epcmark = epc_mark; /* the EPC */
+			jwmarker[jwmarker_num].u.epcmark = epc_mark; /* the EPC */
 			jwmarker[jwmarker_num].pos = soc_pos + socsiz_len; /* after SIZ */
 			jwmarker[jwmarker_num].dpos = (double) jwmarker[jwmarker_num].pos + 0.1; /* not so first */
 			jwmarker[jwmarker_num].len = epc_mark->Lepc; /* its length */
@@ -258,7 +258,7 @@
 			/* Add this marker to the 'insertanda' list */
 			if (jwmarker_num < JPWL_MAX_NO_MARKERS) {
 				jwmarker[jwmarker_num].id = J2K_MS_ESD; /* its type */
-				jwmarker[jwmarker_num].esdmark = esd_mark; /* the EPB */
+				jwmarker[jwmarker_num].u.esdmark = esd_mark; /* the EPB */
 				jwmarker[jwmarker_num].pos = soc_pos + socsiz_len; /* we choose to place it after SIZ */
 				jwmarker[jwmarker_num].dpos = (double) jwmarker[jwmarker_num].pos + 0.2; /* not first at all! */
 				jwmarker[jwmarker_num].len = esd_mark->Lesd; /* its length */
@@ -352,7 +352,7 @@
 					/* Add this marker to the 'insertanda' list */
 					if (jwmarker_num < JPWL_MAX_NO_MARKERS) {
 						jwmarker[jwmarker_num].id = J2K_MS_ESD; /* its type */
-						jwmarker[jwmarker_num].esdmark = esd_mark; /* the EPB */
+						jwmarker[jwmarker_num].u.esdmark = esd_mark; /* the EPB */
 						/****** jwmarker[jwmarker_num].pos = j2k->cstr_info->tile[tileno].start_pos + sot_len + 2; */ /* after SOT */
 						jwmarker[jwmarker_num].pos = j2k->cstr_info->tile[tileno].tp[tpno].tp_start_pos + sot_len + 2; /* after SOT */
 						jwmarker[jwmarker_num].dpos = (double) jwmarker[jwmarker_num].pos + 0.2; /* not first at all! */
@@ -430,7 +430,7 @@
 			/* Add this marker to the 'insertanda' list */
 			if (jwmarker_num < JPWL_MAX_NO_MARKERS) {
 				jwmarker[jwmarker_num].id = J2K_MS_EPB; /* its type */
-				jwmarker[jwmarker_num].epbmark = epb_mark; /* the EPB */
+				jwmarker[jwmarker_num].u.epbmark = epb_mark; /* the EPB */
 				jwmarker[jwmarker_num].pos = soc_pos + socsiz_len; /* after SIZ */
 				jwmarker[jwmarker_num].dpos = (double) jwmarker[jwmarker_num].pos; /* first first first! */
 				jwmarker[jwmarker_num].len = epb_mark->Lepb; /* its length */
@@ -528,7 +528,7 @@
 					/* Add this marker to the 'insertanda' list */
 					if (jwmarker_num < JPWL_MAX_NO_MARKERS) {
 						jwmarker[jwmarker_num].id = J2K_MS_EPB; /* its type */
-						jwmarker[jwmarker_num].epbmark = epb_mark; /* the EPB */
+						jwmarker[jwmarker_num].u.epbmark = epb_mark; /* the EPB */
 						/****** jwmarker[jwmarker_num].pos = j2k->cstr_info->tile[tileno].start_pos + sot_len + 2; */ /* after SOT */
 						jwmarker[jwmarker_num].pos = j2k->cstr_info->tile[tileno].tp[tpno].tp_start_pos + sot_len + 2; /* after SOT */
 						jwmarker[jwmarker_num].dpos = (double) jwmarker[jwmarker_num].pos; /* first first first! */
@@ -758,15 +758,15 @@
 		switch (jwmarker[mm].id) {
 
 		case J2K_MS_EPB:
-			jpwl_epb_write(j2k, jwmarker[mm].epbmark, jpwl_buf);
+			jpwl_epb_write(j2k, jwmarker[mm].u.epbmark, jpwl_buf);
 			break;
 
 		case J2K_MS_EPC:
-			jpwl_epc_write(j2k, jwmarker[mm].epcmark, jpwl_buf);
+			jpwl_epc_write(j2k, jwmarker[mm].u.epcmark, jpwl_buf);
 			break;
 
 		case J2K_MS_ESD:
-			jpwl_esd_write(j2k, jwmarker[mm].esdmark, jpwl_buf);
+			jpwl_esd_write(j2k, jwmarker[mm].u.esdmark, jpwl_buf);
 			break;
 
 		case J2K_MS_RED:
@@ -812,11 +812,11 @@
 			unsigned short int mycrc = 0x0000;
 
 			/* fix and fill the DL field */
-			jwmarker[mm].epcmark->DL = new_size;
-			orig_buf[epc_pos + 6] = (unsigned char) (jwmarker[mm].epcmark->DL >> 24);
-			orig_buf[epc_pos + 7] = (unsigned char) (jwmarker[mm].epcmark->DL >> 16);
-			orig_buf[epc_pos + 8] = (unsigned char) (jwmarker[mm].epcmark->DL >> 8);
-			orig_buf[epc_pos + 9] = (unsigned char) (jwmarker[mm].epcmark->DL >> 0);
+			jwmarker[mm].u.epcmark->DL = new_size;
+			orig_buf[epc_pos + 6] = (unsigned char) (jwmarker[mm].u.epcmark->DL >> 24);
+			orig_buf[epc_pos + 7] = (unsigned char) (jwmarker[mm].u.epcmark->DL >> 16);
+			orig_buf[epc_pos + 8] = (unsigned char) (jwmarker[mm].u.epcmark->DL >> 8);
+			orig_buf[epc_pos + 9] = (unsigned char) (jwmarker[mm].u.epcmark->DL >> 0);
 
 			/* compute the CRC field (excluding itself) */
 			for (pp = 0; pp < 4; pp++)
@@ -825,9 +825,9 @@
 				jpwl_updateCRC16(&mycrc, orig_buf[epc_pos + pp]);
 
 			/* fix and fill the CRC */
-			jwmarker[mm].epcmark->Pcrc = mycrc;
-			orig_buf[epc_pos + 4] = (unsigned char) (jwmarker[mm].epcmark->Pcrc >> 8);
-			orig_buf[epc_pos + 5] = (unsigned char) (jwmarker[mm].epcmark->Pcrc >> 0);
+			jwmarker[mm].u.epcmark->Pcrc = mycrc;
+			orig_buf[epc_pos + 4] = (unsigned char) (jwmarker[mm].u.epcmark->Pcrc >> 8);
+			orig_buf[epc_pos + 5] = (unsigned char) (jwmarker[mm].u.epcmark->Pcrc >> 0);
 
 		}
 	}
@@ -842,7 +842,7 @@
 			/* remember that they are now in a new position (dpos) */
 			int esd_pos = (int) jwmarker[mm].dpos;
 
-			jpwl_esd_fill(j2k, jwmarker[mm].esdmark, &orig_buf[esd_pos]);
+			jpwl_esd_fill(j2k, jwmarker[mm].u.esdmark, &orig_buf[esd_pos]);
 		
 		}
 
@@ -867,16 +867,16 @@
 			accum_len = 0;
 			for (nn = mm; (nn < jwmarker_num) && (jwmarker[nn].id == J2K_MS_EPB) &&
 				(jwmarker[nn].pos == jwmarker[mm].pos); nn++)
-				accum_len += jwmarker[nn].epbmark->Lepb + 2;
+				accum_len += jwmarker[nn].u.epbmark->Lepb + 2;
 
 			/* fill the current (first) EPB with post-data starting from the computed position */
-			jpwl_epb_fill(j2k, jwmarker[mm].epbmark, &orig_buf[(int) jwmarker[mm].dpos],
+			jpwl_epb_fill(j2k, jwmarker[mm].u.epbmark, &orig_buf[(int) jwmarker[mm].dpos],
 				&orig_buf[(int) jwmarker[mm].dpos + accum_len]);
 		
 			/* fill the remaining EPBs in the header with post-data starting from the last position */
 			for (nn = mm + 1; (nn < jwmarker_num) && (jwmarker[nn].id == J2K_MS_EPB) &&
 				(jwmarker[nn].pos == jwmarker[mm].pos); nn++)
-				jpwl_epb_fill(j2k, jwmarker[nn].epbmark, &orig_buf[(int) jwmarker[nn].dpos], NULL);
+				jpwl_epb_fill(j2k, jwmarker[nn].u.epbmark, &orig_buf[(int) jwmarker[nn].dpos], NULL);
 
 			/* skip all the processed EPBs */
 			mm = nn - 1;
