--- ocl_icd_loader.c.orig	2015-06-08 18:29:52 UTC
+++ ocl_icd_loader.c
@@ -49,13 +49,13 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
 #define DEBUG_OCL_ICD_PROVIDE_DUMP_FIELD
 #include "ocl_icd_debug.h"
 
-#define ETC_OPENCL_VENDORS "/etc/OpenCL/vendors"
+#define ETC_OPENCL_VENDORS "/usr/local/etc/OpenCL/vendors"
 
 int debug_ocl_icd_mask=0;
 
 typedef __typeof__(clGetPlatformInfo) *clGetPlatformInfo_fn;
 
-inline void dump_vendor_icd(const char* info, const struct vendor_icd *v) {
+static inline void dump_vendor_icd(const char* info, const struct vendor_icd *v) {
   debug(D_DUMP, "%s %p={ num=%i, handle=%p, f=%p}\n", info,
 	v, v->num_platforms, v->dl_handle, v->ext_fn_ptr);
 }
