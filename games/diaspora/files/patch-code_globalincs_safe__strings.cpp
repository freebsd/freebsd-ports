# Fixes for a couple of clang warnings
# https://github.com/scp-fs2open/fs2open.github.com/commit/5bff2754c267f0e3e5af7d542f09a1760f24f17d

--- code/globalincs/safe_strings.cpp.orig	2012-01-13 18:37:09 UTC
+++ code/globalincs/safe_strings.cpp
@@ -22,11 +22,6 @@
 
 #if !defined(NO_SAFE_STRINGS) && ( !defined( _MSC_VER ) || ( defined( _MSC_VER ) && _MSC_VER >= 1400 /* && !defined(NDEBUG) */ ))
 
-/* We don't have this here - no standard library stuff included */
-#ifndef NULL
-#define NULL 0
-#endif
-
 /* An implementation of strcpy_s 
  * We're not going to actually fully behave like the MS debug version.
  */
@@ -39,14 +34,14 @@ errno_t scp_strcpy_s( const char* file, 
 	if ( !strDest || !strSource )
 	{
 		if ( strDest )
-			*strDest = NULL;
+			*strDest = '\0';
 		__safe_strings_error_handler( EINVAL );
 		return EINVAL;
 	}
 
 	if ( sizeInBytes == 0 )
 	{
-		*strDest = NULL;
+		*strDest = '\0';
 		__safe_strings_error_handler( ERANGE );
 		return ERANGE;
 	}
@@ -58,7 +53,7 @@ errno_t scp_strcpy_s( const char* file, 
 
 	if ( bufferLeft == 0 )
 	{
-		*strDest = NULL;
+		*strDest = '\0';
 		__safe_strings_error_handler( ERANGE );
 		return ERANGE;
 	}
@@ -75,14 +70,14 @@ errno_t scp_strcat_s( const char* file, 
 	if ( !strDest || !strSource )
 	{
 		if ( strDest )
-			*strDest = NULL;
+			*strDest = '\0';
 		__safe_strings_error_handler( EINVAL );
 		return EINVAL;
 	}
 
 	if ( bufferLeft == 0 )
 	{
-		*strDest = NULL;
+		*strDest = '\0';
 		__safe_strings_error_handler( ERANGE );
 		return ERANGE;
 	}
@@ -98,7 +93,7 @@ errno_t scp_strcat_s( const char* file, 
 
 	if ( bufferLeft == 0 )
 	{
-		*strDest = NULL;
+		*strDest = '\0';
 		__safe_strings_error_handler( ERANGE );
 		return ERANGE;
 	}
@@ -108,7 +103,7 @@ errno_t scp_strcat_s( const char* file, 
 
 	if ( bufferLeft == 0 )
 	{
-		*strDest = NULL;
+		*strDest = '\0';
 		__safe_strings_error_handler( ERANGE );
 		return ERANGE;
 	}
