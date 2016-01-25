--- osinfo/osinfo_media.h.orig	2016-01-24 23:58:45 UTC
+++ osinfo/osinfo_media.h
@@ -65,8 +65,6 @@ typedef enum {
 #define OSINFO_IS_MEDIA_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), OSINFO_TYPE_MEDIA))
 #define OSINFO_MEDIA_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), OSINFO_TYPE_MEDIA, OsinfoMediaClass))
 
-typedef struct _OsinfoMedia        OsinfoMedia;
-
 typedef struct _OsinfoMediaClass   OsinfoMediaClass;
 
 typedef struct _OsinfoMediaPrivate OsinfoMediaPrivate;
