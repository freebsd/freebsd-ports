--- lru.c.orig	Mon Aug 23 16:16:41 2004
+++ lru.c	Mon Aug 23 16:16:54 2004
@@ -285,6 +285,7 @@
 				case 'm':
 				}
 				SLsmg_set_color(Col);
+				break;
 			}
 			SLsmg_write_nchars(el->str, len);
 		} while ((el = el->next) != el0);
