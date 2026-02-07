--- src/uudecode.c.orig	2020-08-28 17:15:21 UTC
+++ src/uudecode.c
@@ -82,6 +82,8 @@ static char const cright_years_z[] =
 #define UU_CHMOD(_n, _fd, _m)   chmod ((_n), UU_MODE_BITS(_m))
 #endif
 
+char const * const program_name = "uudecode";
+
 struct passwd *getpwnam ();
 
 static uudecode_exit_code_t read_stduu(
