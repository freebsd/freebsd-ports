--- src/include/firebird/impl/inf_pub.h.orig	2022-12-12 01:05:33 UTC
+++ src/include/firebird/impl/inf_pub.h
@@ -298,6 +298,8 @@ enum  info_db_implementations
 	isc_info_db_impl_linux_m68k = 87,
 	isc_info_db_impl_linux_riscv64 = 88,
 
+	isc_info_db_impl_freebsd_ppc64el = 89,
+
 	isc_info_db_impl_last_value   // Leave this LAST!
 };
 
