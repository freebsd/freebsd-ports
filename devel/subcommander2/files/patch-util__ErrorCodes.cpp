--- util/ErrorCodes.cpp.orig	2006-02-13 00:25:44.000000000 +0900
+++ util/ErrorCodes.cpp	2012-05-10 05:46:12.000000000 +0900
@@ -28,7 +28,7 @@
     }
   }
 
-  return errors[ErrUnknown]._msg;
+  return errors[ErrUnknown - SC_ERR_START]._msg;
 }
 
 } // namespace
