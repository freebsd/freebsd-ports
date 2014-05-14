$OpenBSD: patch-gnome-initial-setup_gis-driver_h,v 1.2 2014/03/27 19:41:05 ajacoutot Exp $

gis-driver.h:40: error: redefinition of typedef 'GisDriver'

--- gnome-initial-setup/gis-driver.h.orig	Mon Mar 10 05:47:29 2014
+++ gnome-initial-setup/gis-driver.h	Thu Mar 27 20:20:44 2014
@@ -35,7 +35,6 @@ G_BEGIN_DECLS
 #define GIS_IS_DRIVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  GIS_TYPE_DRIVER))
 #define GIS_DRIVER_GET_CLASS(obj)                 (G_TYPE_INSTANCE_GET_CLASS ((obj),  GIS_TYPE_DRIVER, GisDriverClass))
 
-typedef struct _GisDriver        GisDriver;
 typedef struct _GisDriverClass   GisDriverClass;
  
  struct _GisDriver
