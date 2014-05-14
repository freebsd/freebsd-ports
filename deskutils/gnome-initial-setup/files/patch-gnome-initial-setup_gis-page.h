$OpenBSD: patch-gnome-initial-setup_gis-page_h,v 1.2 2014/03/27 19:41:05 ajacoutot Exp $

gis-page.h:38: error: redefinition of typedef 'GisPage'

--- gnome-initial-setup/gis-page.h.orig	Mon Mar 10 05:47:29 2014
+++ gnome-initial-setup/gis-page.h	Thu Mar 27 20:20:44 2014
@@ -33,7 +33,6 @@ G_BEGIN_DECLS
 #define GIS_IS_PAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  GIS_TYPE_PAGE))
 #define GIS_PAGE_GET_CLASS(obj)                 (G_TYPE_INSTANCE_GET_CLASS ((obj),  GIS_TYPE_PAGE, GisPageClass))
 
-typedef struct _GisPage        GisPage;
 typedef struct _GisPageClass   GisPageClass;
  typedef struct _GisAssistantPagePrivate GisAssistantPagePrivate;
   
