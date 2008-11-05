
$FreeBSD$

--- erts/emulator/drivers/common/inet_drv.c.orig
+++ erts/emulator/drivers/common/inet_drv.c
@@ -3460,9 +3460,14 @@
     /* Check the size of SCTP AssocID -- currently both this driver and the
        Erlang part require 32 bit: */
     ASSERT(sizeof(sctp_assoc_t)==ASSOC_ID_LEN);
-#   ifndef LIBSCTP
-#     error LIBSCTP not defined
-#   endif
+#   if defined (__FreeBSD__)
+    /* In FreeBSD, sctp_bindx belongs to libc - see sctp_bindx(3) */
+    inet_init_sctp();
+    add_driver_entry(&sctp_inet_driver_entry);
+#   else
+#     ifndef LIBSCTP
+#       error LIBSCTP not defined
+#     endif
     if (erts_sys_ddll_open_noext(STRINGIFY(LIBSCTP), &h_libsctp) == 0) {
 	void *ptr;
 	if (erts_sys_ddll_sym(h_libsctp, "sctp_bindx", &ptr) == 0) {
@@ -3471,6 +3476,7 @@
 	    add_driver_entry(&sctp_inet_driver_entry);
 	}
     }
+#   endif
 #  endif
 #endif /* _OSE_ */
     /* remove the dummy inet driver */
@@ -8997,7 +9003,7 @@
 	    rflag = add_flag ? SCTP_BINDX_ADD_ADDR : SCTP_BINDX_REM_ADDR;
 
 	    /* Invoke the call: */
-	    if (p_sctp_bindx(desc->s, addrs, n, rflag) < 0)
+	    if (sctp_bindx(desc->s, addrs, n, rflag) < 0)
 		return ctl_error(sock_errno(), rbuf, rsize);
 
 	    desc->state = INET_STATE_BOUND;
