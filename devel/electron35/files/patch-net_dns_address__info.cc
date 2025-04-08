--- net/dns/address_info.cc.orig	2024-08-14 20:55:08 UTC
+++ net/dns/address_info.cc
@@ -83,8 +83,12 @@ AddressInfo::AddressInfoAndResult AddressInfo::Get(
     // error.
     // http://crbug.com/134142
     err = ERR_NAME_NOT_RESOLVED;
-#elif BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_FREEBSD)
+#elif BUILDFLAG(IS_POSIX)
+#ifdef EAI_NODATA
     if (os_error != EAI_NONAME && os_error != EAI_NODATA)
+#else
+    if (os_error != EAI_NONAME)
+#endif
       err = ERR_NAME_RESOLUTION_FAILED;
 #endif
 
