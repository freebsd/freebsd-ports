commit c81cb2d87591863cd1d37ccb6143981462f215b7
Author: Austin Shafer <ashafer@nvidia.com>
Date:   Sun May 17 14:14:58 2026 -0400

    nvidia-drm: fix freebsd page offset during nvkms/user memory faults
    
    This fixes the page offset calculation on freebsd with nvidia-drm
    in our nvkms/user memory faults. With this we actually convert
    virtual_address into a page index and use that to index into
    our array of pages.
    
    I found this and ran with it a bit myself, it also recently came
    up and appears to fix a panic that an end user was running into:
    https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=296195
    
    Bug 317957: Clean up module branches
    Reviewed by: rrameshbabu
    Signed-off-for-open-source-by: ashafer
    
    DVS_BUILD_INCLUDE ALL
    MVS_SET_TESTS all
    SUBMIT_GVS_OF_CUSTOM_DVS
    https://builds4u.nvidia.com/dvs/#/change/38366516102499930.6?showTab=DVS

Splitted into per-target.

diff --git nvidia-drm-helper.h.orig nvidia-drm-helper.h
index bc91858136b2..2ef27fced3c5 100644
--- nvidia-drm-helper.h.orig
+++ nvidia-drm-helper.h
@@ -51,6 +51,29 @@
 #define NV_DRM_USE_EXTENDED_PROPERTIES (DRM_OBJECT_MAX_PROPERTY >= 64)
 
 #include <drm/drm_prime.h>
+#include <drm/drm_gem.h>
+#include <linux/mm.h>
+
+/*
+ * nv_drm_vma_fault_get_page_offset - compute GEM page offset from a vm_fault
+ *
+ * On Linux, vmf->pgoff carries the file-level page index set by the VM.
+ * On FreeBSD, linux_cdev_pager_populate() sets vmf->pgoff = 0 and instead
+ * passes the page index (pidx) via vmf->virtual_address as IDX_TO_OFF(pidx).
+ * Convert back with OFF_TO_IDX and subtract the GEM vma_node start to get
+ * the page offset within the GEM object.
+ */
+static inline unsigned long
+nv_drm_vma_fault_get_page_offset(struct vm_fault *vmf,
+                                 struct drm_gem_object *gem)
+{
+#if defined(NV_LINUX)
+    unsigned long offset = vmf->pgoff;
+#else
+    unsigned long offset = OFF_TO_IDX((uintptr_t)vmf->virtual_address);
+#endif
+    return offset - drm_vma_node_start(&gem->vma_node);
+}
 
 static inline struct sg_table*
 nv_drm_prime_pages_to_sg(struct drm_device *dev,
