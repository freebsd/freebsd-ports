--- rlconf.h.orig	2017-02-21 15:25:30 UTC
+++ rlconf.h
@@ -43,7 +43,7 @@
 #define DEFAULT_INPUTRC "~/.inputrc"
 
 /* The ultimate last-ditch filename for an init file -- system-wide. */
-#define SYS_INPUTRC "/etc/inputrc"
+#define SYS_INPUTRC "%%PREFIX%%/etc/inputrc"
 
 /* If defined, expand tabs to spaces. */
 #define DISPLAY_TABS
