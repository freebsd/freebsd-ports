--- src/abraca-medialib.vala.orig	2014-10-26 18:55:55 UTC
+++ src/abraca-medialib.vala
@@ -505,7 +505,11 @@ namespace Abraca {
 				do {
 					urls.get(iter, 0, out current);
 					if (current == url) {
+#if VALA_0_36
+						urls.remove(ref iter);
+#else
 						urls.remove(iter);
+#endif
 						break;
 					}
 				} while (urls.iter_next(ref iter));
