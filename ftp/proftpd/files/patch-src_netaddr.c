Index: src/netaddr.c
===================================================================
RCS file: /cvsroot/proftp/proftpd/src/netaddr.c,v
retrieving revision 1.61
diff -u -r1.61 netaddr.c
--- src/netaddr.c	9 Oct 2007 21:56:23 -0000	1.61
+++ src/netaddr.c	17 Jan 2008 01:34:45 -0000
@@ -816,6 +816,9 @@
     if (pr_netaddr_is_v4mappedv6(na1) == TRUE) {
       tmp_pool = make_sub_pool(permanent_pool);
 
+      pr_trace_msg(trace_channel, 5, "addr '%s' is an IPv4-mapped IPv6 address",
+        pr_netaddr_get_ipstr((pr_netaddr_t *) na1));
+
       /* This case means that na1 is an IPv4-mapped IPv6 address, and
        * na2 is an IPv4 address.
        */
@@ -834,6 +837,9 @@
     } else if (pr_netaddr_is_v4mappedv6(na2) == TRUE) {
       tmp_pool = make_sub_pool(permanent_pool);
 
+      pr_trace_msg(trace_channel, 5, "addr '%s' is an IPv4-mapped IPv6 address",
+        pr_netaddr_get_ipstr((pr_netaddr_t *) na2));
+
       /* This case means that na is an IPv4 address, and na2 is an
        * IPv4-mapped IPv6 address.
        */
@@ -1105,6 +1111,36 @@
         ipstr, pattern);
       return TRUE;
     }
+
+    /* If the address is an IPv4-mapped IPv6 address, get the IPv4 address
+     * and try to match that against the configured glob pattern.
+     */
+    if (pr_netaddr_is_v4mappedv6(na) == TRUE) {
+      pool *tmp_pool;
+      pr_netaddr_t *a;
+
+      pr_trace_msg(trace_channel, 5, "addr '%s' is an IPv4-mapped IPv6 address",
+        ipstr);
+
+      tmp_pool = make_sub_pool(permanent_pool);
+      a = pr_netaddr_alloc(tmp_pool);
+      pr_netaddr_set_family(a, AF_INET);
+      pr_netaddr_set_port(a, pr_netaddr_get_port(na));
+      memcpy(&a->na_addr.v4.sin_addr, get_v4inaddr(na),
+        sizeof(struct in_addr));
+
+      ipstr = pr_netaddr_get_ipstr(a);
+
+      if (pr_fnmatch(pattern, ipstr, match_flags) == 0) {
+        pr_trace_msg(trace_channel, 6, "DNS name '%s' matches pattern '%s'",
+          ipstr, pattern);
+
+        destroy_pool(tmp_pool);
+        return TRUE;
+      }
+
+      destroy_pool(tmp_pool);
+    }
   }
 
   pr_trace_msg(trace_channel, 4, "addr %s does not match pattern '%s'",
@@ -1424,18 +1460,21 @@
 
 #ifdef PR_USE_IPV6
     case AF_INET6: {
+      int res;
+
       if (!use_ipv6) {
         errno = EINVAL;
         return -1;
       }
 
 # ifndef LINUX
-      return IN6_IS_ADDR_V4MAPPED(
+      res = IN6_IS_ADDR_V4MAPPED(
         (struct in6_addr *) pr_netaddr_get_inaddr(na));
 # else
-      return IN6_IS_ADDR_V4MAPPED(
+      res = IN6_IS_ADDR_V4MAPPED(
         ((struct in6_addr *) pr_netaddr_get_inaddr(na))->s6_addr32);
 # endif
+      return res;
     }
 #endif /* PR_USE_IPV6 */
   }
