--- AIO.xs.orig	2022-09-25 16:29:50 UTC
+++ AIO.xs
@@ -2924,7 +2924,7 @@ fexecve (SV *fh, SV *args, SV *envs = &PL_sv_undef)
 	OUTPUT: RETVAL
 
 int
-mount (octet_string special, octet_string path, octet_string fstype, UV flags = 0, octet_string_ornull data = 0)
+mount (octet_string special, octet_string path, UV flags = 0, octet_string_ornull data = 0)
 	CODE:
 #if HAVE_MOUNT
           RETVAL = mount (special, path, fstype, flags, data);
