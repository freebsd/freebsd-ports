--- src/mydns/listen.c.orig	2011-09-05 14:11:54.000000000 +0200
+++ src/mydns/listen.c	2011-09-05 14:13:17.000000000 +0200
@@ -310,7 +310,7 @@
 #if HAVE_IPV6
 			case AF_INET6:
 				memcpy(&addr6, &((struct sockaddr_in6 *)&ifr->ifr_addr)->sin6_addr, sizeof(struct in6_addr));
-				addrlist_add(AF_INET, &addr4, port);
+				addrlist_add(AF_INET, &addr6, port);
 				break;
 #endif
 			default:
@@ -454,7 +454,7 @@
 			if (inet_pton(AF_INET6, addr, &addr6) <= 0)
 				Warnx("%s: `%s' %s: %s", addr, desc, _("address"), _("invalid IPv6 address format"));
 			else
-				addrlist_add(AF_INET6, &addr4, port);
+				addrlist_add(AF_INET6, &addr6, port);
 		}
 #endif
 	}
