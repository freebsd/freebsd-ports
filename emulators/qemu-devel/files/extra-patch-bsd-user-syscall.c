--- a/bsd-user/syscall.c
+++ b/bsd-user/syscall.c
@@ -627,7 +627,7 @@ abi_long do_freebsd_syscall(void *cpu_en
         break;
 
     case TARGET_FREEBSD_NR_fchflags: /* fchflags(2) */
-        ret = do_bsd_fchflags(arg2, arg2);
+        ret = do_bsd_fchflags(arg1, arg2);
         break;
 
     case TARGET_FREEBSD_NR_chroot: /* chroot(2) */
