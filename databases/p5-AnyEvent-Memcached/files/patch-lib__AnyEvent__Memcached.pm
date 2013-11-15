--- ./lib/AnyEvent/Memcached.pm.orig	2010-07-11 12:00:08.000000000 +0200
+++ ./lib/AnyEvent/Memcached.pm	2013-11-15 17:57:36.000000000 +0100
@@ -822,7 +822,7 @@
 				}
 				else {
 					#warn "add failed, try again";
-					$self->incr_add($key,$val,%args);
+					$self->incadd($key,$val,%args);
 				}
 			});
 		}
