--- ocl_icd_loader.c.orig	2017-01-19 13:55:12 UTC
+++ ocl_icd_loader.c
@@ -53,7 +53,7 @@ int debug_ocl_icd_mask=0;
 
 typedef __typeof__(clGetPlatformInfo) *clGetPlatformInfo_fn;
 
-inline void dump_vendor_icd(const char* info, const struct vendor_icd *v) {
+static inline void dump_vendor_icd(const char* info, const struct vendor_icd *v) {
   debug(D_DUMP, "%s %p={ num=%i, handle=%p, f=%p}\n", info,
 	v, v->num_platforms, v->dl_handle, v->ext_fn_ptr);
 }
