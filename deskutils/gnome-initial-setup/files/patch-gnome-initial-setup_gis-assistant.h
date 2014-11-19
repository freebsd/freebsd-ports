$OpenBSD: patch-gnome-initial-setup_gis-assistant_h,v 1.2 2014/03/27 19:41:05 ajacoutot Exp $

gis-assistant.h:38: error: redefinition of typedef 'GisAssistant'

--- gnome-initial-setup/gis-assistant.h.orig	Mon Mar 10 05:47:29 2014
+++ gnome-initial-setup/gis-assistant.h	Thu Mar 27 20:20:44 2014
@@ -33,7 +33,6 @@ G_BEGIN_DECLS
 #define GIS_IS_ASSISTANT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  GIS_TYPE_ASSISTANT))
 #define GIS_ASSISTANT_GET_CLASS(obj)                 (G_TYPE_INSTANCE_GET_CLASS ((obj),  GIS_TYPE_ASSISTANT, GisAssistantClass))
 
-typedef struct _GisAssistant        GisAssistant;
 typedef struct _GisAssistantClass   GisAssistantClass;
  
  struct _GisAssistant
