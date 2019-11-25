--- chrome/browser/metrics/bluetooth_available_utility.cc.orig	2019-09-10 11:13:40 UTC
+++ chrome/browser/metrics/bluetooth_available_utility.cc
@@ -76,8 +76,10 @@ void ReportBluetoothAvailability() {
     return;
   }
 
+#if !defined(OS_BSD)
   device::BluetoothAdapterFactory::Get().GetAdapter(
       base::BindOnce(&OnGetAdapter));
+#endif
 }
 
 }  // namespace bluetooth_utility
