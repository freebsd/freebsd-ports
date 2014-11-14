--- a/bsd-user/freebsd/os-socket.h
+++ b/bsd-user/freebsd/os-socket.h
@@ -181,7 +181,9 @@ static inline abi_long do_bsd_setsockopt
         case IP_PORTRANGE: /* int; range to choose for unspec port */
         case IP_RECVIF: /* bool; receive reception if w/dgram */
         case IP_IPSEC_POLICY:   /* int; set/get security policy */
+#ifdef IP_FAITH
         case IP_FAITH:  /* bool; accept FAITH'ed connections */
+#endif
         case IP_RECVTTL: /* bool; receive reception TTL w/dgram */
             val = 0;
             if (optlen >= sizeof(uint32_t)) {
@@ -454,7 +456,9 @@ int_case:
         case IP_MULTICAST_LOOP:
         case IP_PORTRANGE:
         case IP_IPSEC_POLICY:
+#ifdef IP_FAITH
         case IP_FAITH:
+#endif
         case IP_ONESBCAST:
         case IP_BINDANY:
             if (get_user_u32(len, optlen)) {
