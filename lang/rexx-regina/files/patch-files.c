--- files.c.orig	2015-04-04 05:20:44 UTC
+++ files.c
@@ -4252,9 +4252,9 @@ static streng *getstatus( tsd_t *TSD, co
             sprintf( result->value, "%I64u", buffer.st_ctime );
 #else
             if ( sizeof(off_t) > 4 )
-               sprintf( result->value, "%lld", buffer.st_ctime );
+               sprintf( result->value, "%lld", (long long) buffer.st_ctime );
             else
-               sprintf( result->value, "%ld", buffer.st_ctime);
+               sprintf( result->value, "%ld", (long) buffer.st_ctime);
 #endif
          }
          break;
@@ -4270,9 +4270,9 @@ static streng *getstatus( tsd_t *TSD, co
             sprintf( result->value, "%I64u", buffer.st_mtime );
 #else
             if ( sizeof(off_t) > 4 )
-               sprintf( result->value, "%lld", buffer.st_mtime );
+               sprintf( result->value, "%lld", (long long) buffer.st_mtime );
             else
-               sprintf( result->value, "%ld", buffer.st_mtime);
+               sprintf( result->value, "%ld", (long) buffer.st_mtime);
 #endif
          }
          break;
@@ -4288,9 +4288,9 @@ static streng *getstatus( tsd_t *TSD, co
             sprintf( result->value, "%I64u", buffer.st_atime );
 #else
             if ( sizeof(off_t) > 4 )
-               sprintf( result->value, "%lld", buffer.st_atime );
+               sprintf( result->value, "%lld", (long long) buffer.st_atime );
             else
-               sprintf( result->value, "%ld", buffer.st_atime);
+               sprintf( result->value, "%ld", (long) buffer.st_atime);
 #endif
          }
          break;
@@ -6061,7 +6061,7 @@ static streng *get_external_routine_file
    if ( *fp == NULL )
       return NULL;
 
-   my_fullpath( TSD, buf, inname );
+   my_fullpath( (tsd_t *) TSD, buf, inname );
 
    return Str_crestrTSD( buf );
 }
@@ -6673,7 +6673,7 @@ int my_fullpathstreng( const tsd_t *TSD,
    int retval;
 
    copy = str_ofTSD( src );
-   retval = my_fullpath( TSD, dst, copy );
+   retval = my_fullpath( (tsd_t *) TSD, dst, copy );
    FreeTSD( copy );
 
    return retval;
