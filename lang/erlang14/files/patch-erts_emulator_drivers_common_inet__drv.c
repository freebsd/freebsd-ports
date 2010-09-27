
$FreeBSD$

--- erts/emulator/drivers/common/inet_drv.c.orig
+++ erts/emulator/drivers/common/inet_drv.c
@@ -3452,17 +3452,9 @@
     /* Check the size of SCTP AssocID -- currently both this driver and the
        Erlang part require 32 bit: */
     ASSERT(sizeof(sctp_assoc_t)==ASSOC_ID_LEN);
-#   ifndef LIBSCTP
-#     error LIBSCTP not defined
-#   endif
-    if (erts_sys_ddll_open_noext(STRINGIFY(LIBSCTP), &h_libsctp, NULL) == 0) {
-	void *ptr;
-	if (erts_sys_ddll_sym(h_libsctp, "sctp_bindx", &ptr) == 0) {
-	    p_sctp_bindx = ptr;
-	    inet_init_sctp();
-	    add_driver_entry(&sctp_inet_driver_entry);
-	}
-    }
+    p_sctp_bindx = sctp_bindx;
+    inet_init_sctp();
+    add_driver_entry(&sctp_inet_driver_entry);
 #endif
 
     /* remove the dummy inet driver */
@@ -5293,12 +5285,14 @@
 	    if (pmtud_enable)			cflags |= SPP_PMTUD_ENABLE;
 	    if (pmtud_disable)			cflags |= SPP_PMTUD_DISABLE;
 
+#	    ifdef HAVE_STRUCT_SCTP_PADDRPARAMS_SPP_SACKDELAY
 	    sackdelay_enable =eflags& SCTP_FLAG_SACDELAY_ENABLE;
 	    sackdelay_disable=eflags& SCTP_FLAG_SACDELAY_DISABLE;
 	    if (sackdelay_enable && sackdelay_disable)
 		return -1;
 	    if (sackdelay_enable)		cflags |= SPP_SACKDELAY_ENABLE;
 	    if (sackdelay_disable)		cflags |= SPP_SACKDELAY_DISABLE;
+#           endif
 
 	    arg.pap.spp_flags  = cflags;
 #	    endif
@@ -6200,12 +6194,14 @@
 	    if (ap.spp_flags & SPP_PMTUD_DISABLE)
 		{ i = LOAD_ATOM (spec, i, am_pmtud_disable);         n++; }
 	    
+#	    ifdef HAVE_STRUCT_SCTP_PADDRPARAMS_SPP_SACKDELAY
 	    if (ap.spp_flags & SPP_SACKDELAY_ENABLE)
 		{ i = LOAD_ATOM (spec, i, am_sackdelay_enable);      n++; }
 	    
 	    if (ap.spp_flags & SPP_SACKDELAY_DISABLE)
 		{ i = LOAD_ATOM (spec, i, am_sackdelay_disable);     n++; }
 #	    endif
+#	    endif
 	    
 	    PLACE_FOR(spec, i,
 		      LOAD_NIL_CNT + LOAD_LIST_CNT + 2*LOAD_TUPLE_CNT);
