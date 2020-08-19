commit bd4380c63c3b8b8b5f60dc840809dbe96a222fd7
Author: Bas Nieuwenhuizen <bas@basnieuwenhuizen.nl>
Date:   Tue Jan 21 11:49:55 2020 +0100

    radv: Remove syncobj_handle variable in header.
    
    I strongly suspect it was supposed to be a typedef. However, used
    nowhere, we should remove it.
    
    Fixes: eaa56eab6da "radv: initial support for shared semaphores (v2)"
    Closes: https://gitlab.freedesktop.org/mesa/mesa/issues/2385
    Reviewed-by: Michel Dänzer <mdaenzer@redhat.com>
    Reviewed-by: Samuel Pitoiset <samuel.pitoiset@gmail.com>
    Tested-by: Marge Bot <https://gitlab.freedesktop.org/mesa/mesa/merge_requests/3479>
    Part-of: <https://gitlab.freedesktop.org/mesa/mesa/merge_requests/3479>

diff --git src/amd/vulkan/radv_radeon_winsys.h src/amd/vulkan/radv_radeon_winsys.h
index c8790917bcc..5c7b1ab5118 100644
--- src/amd/vulkan/radv_radeon_winsys.h
+++ src/amd/vulkan/radv_radeon_winsys.h
@@ -156,7 +156,6 @@ struct radeon_bo_metadata {
 	uint32_t                metadata[64];
 };
 
-uint32_t syncobj_handle;
 struct radeon_winsys_fence;
 
 struct radeon_winsys_bo {
