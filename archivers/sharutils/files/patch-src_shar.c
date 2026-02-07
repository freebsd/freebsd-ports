--- src/shar.c.orig	2020-08-28 17:03:20 UTC
+++ src/shar.c
@@ -83,6 +83,8 @@ static const char cright_years_z[] =
 
 #define LOG10_MAX_INT  11
 
+char const * const program_name = "shar";
+
 /* System related declarations.  */
 
 /* Convert a possibly-signed character to an unsigned character.  This is
