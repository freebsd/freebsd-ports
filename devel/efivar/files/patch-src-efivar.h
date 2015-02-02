--- src/efivar.h.orig	2014-10-15 15:48:49.000000000 +0200
+++ src/efivar.h	2015-01-19 15:32:22.000000000 +0100
@@ -25,7 +25,6 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
-#include <byteswap.h>
 
 typedef struct {
 	uint32_t	a;
@@ -40,7 +39,7 @@ typedef struct {
 #endif
 
 #define EFI_GUID(a,b,c,d,e0,e1,e2,e3,e4,e5) \
-((efi_guid_t) {(a), (b), (c), bswap_16(d), { (e0), (e1), (e2), (e3), (e4), (e5) }})
+((efi_guid_t) {(a), (b), (c), bswap16(d), { (e0), (e1), (e2), (e3), (e4), (e5) }})
 
 #define EFI_GLOBAL_GUID EFI_GUID(0x8be4df61,0x93ca,0x11d2,0xaa0d,0x00,0xe0,0x98,0x03,0x2b,0x8c)
 
@@ -85,7 +84,7 @@ efi_set_variable(efi_guid_t guid, const 
 		return -1;
 	}
 
-	if (__va_arg_pack_len() == 0)
+	if (__builtin_va_arg_pack_len() == 0)
 		return _efi_set_variable(guid, name, data, data_size,
 					 attributes, 0644);
 
