--- src/arg_parse.c.orig	2022-03-10 02:50:47 UTC
+++ src/arg_parse.c
@@ -27,6 +27,7 @@ static void permute( const char *argv[], int *first_no
 static int parse_short_opt( int argc, const char *const argv[], const Options *options, Option *option );
 static int parse_long_opt( int argc, const char *const argv[], const Options *options, Option *option );
 
+#ifndef __FreeBSD__
 /*!
  * \brief Locate a character in a a string.
  * 
@@ -36,6 +37,7 @@ static int parse_long_opt( int argc, const char *const
  *         otherwise the pointer to the terminating NUL character of \p s
  */
 static char *strchrnul( const char *s, int c );
+#endif
 
 Option parse_args( int argc, const char *argv[], const Options *options )
 {
@@ -251,9 +253,11 @@ static int parse_long_opt( int argc, const char *const
 	return argn;  // which arg in argv that parse_args() should examine when called again
 }
 
+#ifndef __FreeBSD__
 static char *strchrnul( const char *s, int c )
 {
 	for (; *s != c && *s != '\0'; ++s)
 		;
 	return (char *)s;
 }
+#endif
