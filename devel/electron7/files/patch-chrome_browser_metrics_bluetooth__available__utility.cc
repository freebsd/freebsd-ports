--- chrome/browser/metrics/bluetooth_available_utility.cc.orig	2019-12-12 12:39:11 UTC
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
