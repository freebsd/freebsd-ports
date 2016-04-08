--- mk/Autoconf.mk.orig	2016-03-24 14:39:02 UTC
+++ mk/Autoconf.mk
@@ -110,20 +110,14 @@ ac_binary = $(shell \
 #	$(call ac_fini))
 ac_lib64 = $(shell \
 	$(call ac_init,for libdir name);\
-	$(call ac_s_cmd,/sbin/ldconfig -p | grep -q lib64 &&\
+	$(call ac_s_cmd,$(CC) -print-search-dirs | grep -q lib64 &&\
 		echo "lib64" || echo "lib");\
 	$(call ac_fini))
 
 # check for x11 ressource dir prefix
 ac_resdir = $(shell \
 	$(call ac_init,for X11 app-defaults prefix);\
-	$(call ac_s_cmd, for dir in \
-		/etc/X11/app-defaults \
-		/usr/X11R6/lib/X11/app-defaults \
-		/usr/share/X11/app-defaults \
-		/usr/lib/X11/app-defaults \
-		; do test -d "$$dir" || continue;\
-		dirname "$$dir"; break; done);\
+	$(call ac_s_cmd, dirname "${PREFIX}/lib/X11/app-defaults");\
 	$(call ac_fini))
 
 # check if package is installed, via pkg-config
