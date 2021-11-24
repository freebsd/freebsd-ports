--- ui/base/dragdrop/os_exchange_data_provider_non_backed.cc.orig	2021-07-15 19:14:08 UTC
+++ ui/base/dragdrop/os_exchange_data_provider_non_backed.cc
@@ -102,14 +102,14 @@ void OSExchangeDataProviderNonBacked::SetPickledData(
 }
 
 bool OSExchangeDataProviderNonBacked::GetString(std::u16string* data) const {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (HasFile()) {
     // Various Linux file managers both pass a list of file:// URIs and set the
     // string representation to the URI. We explicitly don't want to return use
     // this representation.
     return false;
   }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   if ((formats_ & OSExchangeData::STRING) == 0)
     return false;
