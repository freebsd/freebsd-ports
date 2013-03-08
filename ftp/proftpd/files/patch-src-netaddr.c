--- src/netaddr.c.orig	2013-03-08 23:51:40.640634650 +0100
+++ src/netaddr.c	2013-03-08 23:52:10.317608901 +0100
@@ -690,8 +690,8 @@
         pr_freeaddrinfo(info);
       }
     }
-#endif /* PR_USE_IPV6 */
   }
+#endif /* PR_USE_IPV6 */
 
   return na;
 }
