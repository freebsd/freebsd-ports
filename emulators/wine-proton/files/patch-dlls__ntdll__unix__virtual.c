--- dlls/ntdll/unix/virtual.c.orig
+++ dlls/ntdll/unix/virtual.c
@@ -1562,7 +1562,6 @@ static NTSTATUS create_view( struct file_view **view_ret, void *base, size_t siz
 
     if (vprot & VPROT_WRITEWATCH && use_kernel_writewatch)
     {
-        madvise( view->base, view->size, MADV_NOHUGEPAGE );
         reset_write_watches( view->base, view->size );
     }
 
@@ -2158,7 +2157,6 @@ static NTSTATUS map_view( struct file_view **view_ret, void *base, size_t size,
                 ERR("set_protection failed.\n");
             if (vprot & VPROT_WRITEWATCH)
             {
-                madvise( base, size, MADV_NOHUGEPAGE );
                 reset_write_watches( base, size );
             }
             return STATUS_SUCCESS;
