--- a/bsd-user/freebsd/os-sys.c
+++ b/bsd-user/freebsd/os-sys.c
@@ -75,8 +75,10 @@ host_to_target_vfc_flags(int flags)
 	ret |= TARGET_VFCF_JAIL;
     if (flags & VFCF_DELEGADMIN)
 	ret |= TARGET_VFCF_DELEGADMIN;
+#ifdef VFCF_SBDRY
     if (flags & VFCF_SBDRY)
 	ret |= TARGET_VFCF_SBDRY;
+#endif
 
     return ret;
 }
