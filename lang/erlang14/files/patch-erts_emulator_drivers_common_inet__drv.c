
$FreeBSD$

--- erts/emulator/drivers/common/inet_drv.c.orig
+++ erts/emulator/drivers/common/inet_drv.c
@@ -5305,12 +5305,15 @@
 	    if (pmtud_enable)			cflags |= SPP_PMTUD_ENABLE;
 	    if (pmtud_disable)			cflags |= SPP_PMTUD_DISABLE;
 
+#	    ifdef HAVE_STRUCT_SCTP_PADDRPARAMS_SPP_SACKDELAY
+	    /* The followings are missing in FreeBSD 7.1 */
 	    sackdelay_enable =eflags& SCTP_FLAG_SACDELAY_ENABLE;
 	    sackdelay_disable=eflags& SCTP_FLAG_SACDELAY_DISABLE;
 	    if (sackdelay_enable && sackdelay_disable)
 		return -1;
 	    if (sackdelay_enable)		cflags |= SPP_SACKDELAY_ENABLE;
 	    if (sackdelay_disable)		cflags |= SPP_SACKDELAY_DISABLE;
+#           endif
 
 	    arg.pap.spp_flags  = cflags;
 #	    endif
@@ -6211,13 +6214,15 @@
 	    
 	    if (ap.spp_flags & SPP_PMTUD_DISABLE)
 		{ i = LOAD_ATOM (spec, i, am_pmtud_disable);         n++; }
-	    
+#	    ifdef HAVE_STRUCT_SCTP_PADDRPARAMS_SPP_SACKDELAY
+	    /* SPP_SACKDELAY_* not in FreeBSD 7.1 */
 	    if (ap.spp_flags & SPP_SACKDELAY_ENABLE)
 		{ i = LOAD_ATOM (spec, i, am_sackdelay_enable);      n++; }
 	    
 	    if (ap.spp_flags & SPP_SACKDELAY_DISABLE)
 		{ i = LOAD_ATOM (spec, i, am_sackdelay_disable);     n++; }
 #	    endif
+#	    endif
 	    
 	    PLACE_FOR(spec, i,
 		      LOAD_NIL_CNT + LOAD_LIST_CNT + 2*LOAD_TUPLE_CNT);
