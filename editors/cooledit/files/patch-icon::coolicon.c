--- icon/coolicon.c.orig	Mon Jun  7 11:23:06 1999
+++ icon/coolicon.c	Mon Jun  7 11:24:05 1999
@@ -49,7 +49,7 @@
 void free_icon_elements (CPowerIcon * icon);
 void free_all_lists (void);
 
-#define SYSTEM_ICONS LIBDIR "/coolicon.config"
+#define SYSTEM_ICONS SYSCONFDIR "/coolicon.config"
 #define E_DATA LIBDIR "/e.data"
 #define START_WIDTH size_of_e
 #define START_HEIGHT size_of_e
