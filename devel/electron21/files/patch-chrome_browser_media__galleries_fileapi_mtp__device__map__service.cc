--- chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc
@@ -39,10 +39,12 @@ void MTPDeviceMapService::RegisterMTPFileSystem(
     // Note that this initializes the delegate asynchronously, but since
     // the delegate will only be used from the IO thread, it is guaranteed
     // to be created before use of it expects it to be there.
+#if !defined(OS_BSD) 
     CreateMTPDeviceAsyncDelegate(
         device_location, read_only,
         base::BindOnce(&MTPDeviceMapService::AddAsyncDelegate,
                        base::Unretained(this), device_location, read_only));
+#endif
     mtp_device_usage_map_[key] = 0;
   }
 
