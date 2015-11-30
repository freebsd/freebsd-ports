--- setuppagelogsnew.cpp.orig	2015-09-15 18:40:58 UTC
+++ setuppagelogsnew.cpp
@@ -735,6 +735,7 @@ bool SetupPageLogsNew::isThereAnyNotMana
         //qDebug() << "SetupPageLogsNew::isThereAnyNotManagedLog tras el while" << endl;
     }
     //qDebug() << "SetupPageLogsNew::isThereAnyNotManagedLog END" << endl;
+    return true;
 }
 
 void SetupPageLogsNew::setStationCallSign(const QString _st)
