--- src/libgdl/gdl-dock-object.h.orig	2013-10-16 23:18:22.000000000 +0200
+++ src/libgdl/gdl-dock-object.h	2013-10-17 12:02:38.000000000 +0200
@@ -215,7 +215,7 @@
     G_STMT_START {                            \
     g_log (G_LOG_DOMAIN,                      \
 	   G_LOG_LEVEL_DEBUG,                 \
-           "%s:%d (%s) %s [%p %d%s:%d]: "format, \
+           "%s:%d (%s) %s [%p %d%s:%d]: " format, \
 	   __FILE__,                          \
 	   __LINE__,                          \
 	   __PRETTY_FUNCTION__,               \
