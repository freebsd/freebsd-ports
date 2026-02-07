--- videocapt/cameradialog.cpp.orig	2019-04-19 07:07:41 UTC
+++ videocapt/cameradialog.cpp
@@ -220,7 +220,8 @@ void cameraDialog::getCameraInfo(QString
       formats=getFormatList(fd);
       if(ok)
         {
-          cameraList.append(scameraDevice(camDev,(const char *)cap.card,(const char *)cap.driver,(const char *)cap.bus_info,formats));
+          if (formats.count() > 0)
+            cameraList.append(scameraDevice(camDev,(const char *)cap.card,(const char *)cap.driver,(const char *)cap.bus_info,formats));
         }
       v4l2_close(fd);
     }
