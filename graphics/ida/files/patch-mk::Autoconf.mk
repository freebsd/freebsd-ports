--- mk/Autoconf.mk.old	2009-05-24 18:47:11.000000000 +0300
+++ mk/Autoconf.mk	2009-05-24 18:49:32.000000000 +0300
@@ -118,9 +118,9 @@
 	$(call ac_init,for X11 app-defaults prefix);\
 	$(call ac_s_cmd, for dir in \
 		/etc/X11/app-defaults \
-		/usr/X11R6/lib/X11/app-defaults \
-		/usr/share/X11/app-defaults \
-		/usr/lib/X11/app-defaults \
+		${PREFIX}/lib/X11/app-defaults \
+		${PREFIX}/share/X11/app-defaults \
+		${PREFIX}/lib/X11/app-defaults \
 		; do test -d "$$dir" || continue;\
 		dirname "$$dir"; break; done);\
 	$(call ac_fini))
