--- src/VBox/Devices/Storage/DrvHostBase-freebsd.cpp	2020-09-17 20:17:20 UTC
+++ src/VBox/Devices/Storage/DrvHostBase-freebsd.cpp
@@ -149,6 +149,8 @@ 
         else
             rc = RTErrConvertFromErrno(errno);
     }
+
+    return rc;
 }
 
 
