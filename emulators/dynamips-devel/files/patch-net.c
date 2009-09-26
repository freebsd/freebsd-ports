--- net.c.orig	2009-07-20 16:23:20.000000000 +0400
+++ net.c	2009-07-20 16:24:14.000000000 +0400
@@ -209,6 +209,7 @@
       addr->eth_addr_byte[3] = v[1] & 0xFF;
       addr->eth_addr_byte[4] = (v[2] >> 8) & 0xFF;
       addr->eth_addr_byte[5] = v[2] & 0xFF;
+      return(0);
    }
 
    return(-1);
