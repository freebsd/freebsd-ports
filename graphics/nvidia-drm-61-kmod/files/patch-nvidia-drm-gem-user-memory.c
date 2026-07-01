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

diff --git nvidia-drm-gem-user-memory.c.orig nvidia-drm-gem-user-memory.c
index 5ce0ba890e52..0ca3a7e2e07d 100644
--- nvidia-drm-gem-user-memory.c.orig
+++ nvidia-drm-gem-user-memory.c
@@ -144,7 +144,7 @@ static vm_fault_t __nv_drm_gem_user_memory_handle_vma_fault(
     unsigned long page_offset;
     unsigned long pfn;
 
-    page_offset = vmf->pgoff - drm_vma_node_start(&gem->vma_node);
+    page_offset = nv_drm_vma_fault_get_page_offset(vmf, gem);
     BUG_ON(page_offset >= nv_user_memory->pages_count);
     pfn = page_to_pfn(nv_user_memory->pages[page_offset]);
 
