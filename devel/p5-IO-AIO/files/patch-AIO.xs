--- AIO.xs.orig	2022-09-28 08:22:50 UTC
+++ AIO.xs
@@ -169,9 +169,11 @@
 # include <sys/eventfd.h>
 #endif
 
+#define cv condvar_cv
 #if HAVE_TIMERFD
 # include <sys/timerfd.h>
 #endif
+#undef cv
 
 #if HAVE_RLIMITS
   #include <sys/time.h>
@@ -2926,7 +2928,7 @@ fexecve (SV *fh, SV *args, SV *envs = &PL_sv_undef)
 	OUTPUT: RETVAL
 
 int
-mount (octet_string special, octet_string path, octet_string fstype, UV flags = 0, octet_string_ornull data = 0)
+mount (octet_string special, octet_string path, UV flags = 0, octet_string_ornull data = 0)
 	CODE:
 #if HAVE_MOUNT
           RETVAL = mount (special, path, fstype, flags, data);
