--- hk_kdeclasses/hk_kdedblistview.cpp.orig	Thu Jul 15 23:11:07 2004
+++ hk_kdeclasses/hk_kdedblistview.cpp	Thu Jul 15 23:19:51 2004
@@ -634,7 +634,7 @@
     if (xtype=="DATABASE"
         && !(database()->connection()&&database()->connection()->server_supports(hk_connection::SUPPORTS_NEW_DATABASE)))
         cancreate=false;
-   return (event->provides("application/x-hk_filecopy")&&event->source()!=this && cancreate);
+   return (event->provides("application/x-hk_filecopy")&&event->source()!=(QWidget*)this && cancreate);
 }
 
 
