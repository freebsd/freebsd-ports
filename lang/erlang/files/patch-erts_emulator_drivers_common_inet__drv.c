
$FreeBSD$

--- erts/emulator/drivers/common/inet_drv.c.orig
+++ erts/emulator/drivers/common/inet_drv.c
@@ -3455,17 +3455,9 @@
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
