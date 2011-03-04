--- ./src/CDBus.h.orig	2011-02-16 22:32:47.000000000 +0200
+++ ./src/CDBus.h	2011-02-26 17:27:33.000000000 +0200
@@ -34,7 +34,6 @@
         void loadGeoData(const QString& filename);
         void zoomToRect(const double lon1, const double lat1, const double lon2, const double lat2);
         void setWaypointIcon(const QString& name, const QByteArray& data);
-//        void setWaypointIconFile(const QString& name, const QString& filename);
 
     private:
         friend class CMainWindow;
