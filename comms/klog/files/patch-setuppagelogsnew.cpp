--- setuppagelogsnew.cpp.orig	2015-04-27 23:19:32.000000000 -0700
+++ setuppagelogsnew.cpp	2015-04-27 23:19:49.000000000 -0700
@@ -724,6 +724,7 @@
         //qDebug() << "SetupPageLogsNew::isThereAnyNotManagedLog tras el while" << endl;
     }
     //qDebug() << "SetupPageLogsNew::isThereAnyNotManagedLog END" << endl;
+    return true;
 }
 
 void SetupPageLogsNew::setStationCallSign(const QString _st)
