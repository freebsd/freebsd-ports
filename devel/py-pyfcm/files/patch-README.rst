--- README.rst.orig	2017-10-18 23:26:43 UTC
+++ README.rst
@@ -119,8 +119,8 @@ Send a data message.
     # To send extra kwargs (keyword arguments not provided in any of the methods),
     # pass it as a key value in a dictionary to the method being used
     extra_kwargs = {
-        'priority': 'high'
-    }
+        'priority': 'high'
+    }
     result = push_service.notify_single_device(registration_id=registration_id, data_message=data_message, extra_kwargs=extra_kwargs)
 
     # To process background notifications in iOS 10, set content_available
