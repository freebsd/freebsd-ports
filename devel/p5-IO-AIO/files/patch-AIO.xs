--- AIO.xs.orig	2022-09-05 08:40:14 UTC
+++ AIO.xs
@@ -2924,7 +2924,7 @@ fexecve (SV *fh, SV *args, SV *envs = &PL_sv_undef)
 	OUTPUT: RETVAL
 
 int
-mount (octet_string special, octet_string path, octet_string fstype, UV flags = 0, octet_string_ornull data = 0)
+mount (octet_string special, octet_string path, UV flags = 0, octet_string_ornull data = 0)
         OUTPUT: RETVAL
 
 int
