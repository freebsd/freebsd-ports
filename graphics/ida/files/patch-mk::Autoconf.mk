--- mk/Autoconf.mk.old	Fri Aug 20 21:07:52 2004
+++ mk/Autoconf.mk	Fri Aug 20 21:08:23 2004
@@ -107,7 +107,7 @@
 ac_resdir = $(shell \
 	$(call ac_init,for X11 app-defaults prefix);\
 	$(call ac_s_cmd, test -d /etc/X11/app-defaults &&\
-		echo "/etc/X11" || echo "/usr/X11R6/lib/X11");\
+		echo "/etc/X11" || echo "$(PREFIX)/lib/X11");\
 	$(call ac_fini))
 
 
