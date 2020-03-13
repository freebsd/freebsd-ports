--- chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc.orig	2019-12-12 12:39:10 UTC
+++ chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc
@@ -21,6 +21,7 @@ static base::LazyInstance<scoped_refptr<StorageDeviceL
 
 void RemovableStorageProvider::GetAllDevices(DeviceListReadyCallback callback) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
+#if !defined(OS_BSD)
   if (g_test_device_list.Get().get() != nullptr) {
     base::ThreadTaskRunnerHandle::Get()->PostTask(
         FROM_HERE,
@@ -34,6 +35,9 @@ void RemovableStorageProvider::GetAllDevices(DeviceLis
        base::TaskShutdownBehavior::SKIP_ON_SHUTDOWN},
       base::BindOnce(&RemovableStorageProvider::PopulateDeviceList),
       std::move(callback));
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 // static
