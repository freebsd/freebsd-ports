--- mk/Autoconf.mk.orig	2008-06-09 17:56:36.000000000 +0300
+++ mk/Autoconf.mk	2009-05-28 08:51:09.000000000 +0300
@@ -109,7 +109,7 @@
 #	$(call ac_fini))
 ac_lib64 = $(shell \
 	$(call ac_init,for libdir name);\
-	$(call ac_s_cmd,/sbin/ldconfig -p | grep -q lib64 &&\
+	$(call ac_s_cmd,$(CC) -print-search-dirs | grep -q lib64 &&\
 		echo "lib64" || echo "lib");\
 	$(call ac_fini))
 
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
