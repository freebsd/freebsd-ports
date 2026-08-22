--- dlls/ntdll/unix/system.c.orig	2026-08-21 20:25:07 UTC
+++ dlls/ntdll/unix/system.c
@@ -1517,7 +1517,7 @@ static NTSTATUS add_hwloc_numa_nodes(hwloc_topology_t 
 
     for (obj = hwloc_get_obj_by_type(topology, HWLOC_OBJ_NUMANODE, 0); obj != NULL; obj = obj->next_cousin)
     {
-        if (!logical_proc_info_add_numa_node(obj->logical_index, hwloc_bitmap_to_ulong(obj->cpuset)))
+        if (!logical_proc_info_add_numa_node(hwloc_bitmap_to_ulong(obj->cpuset), obj->logical_index))
             return STATUS_NO_MEMORY;
     }
     return STATUS_SUCCESS;
