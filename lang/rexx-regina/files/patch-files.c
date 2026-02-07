--- files.c.orig	2019-10-06 06:09:39 UTC
+++ files.c
@@ -76,6 +76,8 @@
  * flag, which all other routines will check for.
  */
 
+#pragma clang diagnostic ignored "-Wincompatible-pointer-types-discards-qualifiers"
+
 /*
  * Bug in LCC complier wchar.h that incorrectly says it defines stat struct
  * but doesn't
@@ -4139,14 +4141,14 @@ static streng *getstatus( tsd_t *TSD, const streng *fi
 #else
          if ( sizeof(rx_64) > 4 )
             sprintf( result->value,
-               "%ld %ld %03o %d %s %s %lld",
+               "%ld %ld %03o %lu %s %s %ld",
                (long)(buffer.st_dev), (long)(buffer.st_ino),
                buffer.st_mode & ACCESSPERMS, buffer.st_nlink,
                ptmppwd, ptmpgrp,
                (rx_64)(buffer.st_size) ) ;
          else
             sprintf( result->value,
-               "%ld %ld %03o %d %s %s %ld",
+               "%ld %ld %03o %lu %s %s %ld",
                (long)(buffer.st_dev), (long)(buffer.st_ino),
                buffer.st_mode & ACCESSPERMS, buffer.st_nlink,
                ptmppwd, ptmpgrp,
@@ -4181,7 +4183,7 @@ static streng *getstatus( tsd_t *TSD, const streng *fi
             sprintf( result->value, "%I64u", buffer.st_size ) ;
 #else
             if ( sizeof(rx_64) > 4 )
-               sprintf( result->value, "%lld", (rx_64)(buffer.st_size) ) ;
+               sprintf( result->value, "%ld", (rx_64)(buffer.st_size) ) ;
             else
                sprintf( result->value, "%ld", (long)(buffer.st_size) ) ;
 #endif
@@ -4259,9 +4261,9 @@ static streng *getstatus( tsd_t *TSD, const streng *fi
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
@@ -4277,9 +4279,9 @@ static streng *getstatus( tsd_t *TSD, const streng *fi
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
@@ -4295,9 +4297,9 @@ static streng *getstatus( tsd_t *TSD, const streng *fi
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
@@ -4310,7 +4312,7 @@ static streng *getstatus( tsd_t *TSD, const streng *fi
             sprintf( result->value, "%I64u", pos_read + 1 );
 #else
             if ( sizeof(off_t) > 4 )
-               sprintf( result->value, "%lld", pos_read + 1 );
+               sprintf( result->value, "%ld", pos_read + 1 );
             else
                sprintf( result->value, "%ld", (long)(pos_read + 1) );
 #endif
@@ -4326,7 +4328,7 @@ static streng *getstatus( tsd_t *TSD, const streng *fi
             sprintf( result->value, "%I64u", pos_write + 1 );
 #else
             if ( sizeof(off_t) > 4 )
-               sprintf( result->value, "%lld", pos_write + 1 );
+               sprintf( result->value, "%ld", pos_write + 1 );
             else
                sprintf( result->value, "%ld", (long)(pos_write + 1) );
 #endif
@@ -4342,7 +4344,7 @@ static streng *getstatus( tsd_t *TSD, const streng *fi
             sprintf( result->value, "%I64u", line_read );
 #else
             if ( sizeof(off_t) > 4 )
-               sprintf( result->value, "%lld", line_read );
+               sprintf( result->value, "%ld", line_read );
             else
                sprintf( result->value, "%ld", (long)line_read );
 #endif
@@ -4388,7 +4390,7 @@ static streng *getstatus( tsd_t *TSD, const streng *fi
             sprintf( result->value, "%I64u", line_write + 1 );
 #else
             if ( sizeof(off_t) > 4 )
-               sprintf( result->value, "%lld", line_write + 1 ) ;
+               sprintf( result->value, "%ld", line_write + 1 ) ;
             else
                sprintf( result->value, "%ld", (long)(line_write + 1) ) ;
 #endif
@@ -4401,7 +4403,7 @@ static streng *getstatus( tsd_t *TSD, const streng *fi
             sprintf( result->value, "%I64u", line_write );
 #else
             if ( sizeof(off_t) > 4 )
-               sprintf( result->value, "%lld", line_write ) ;
+               sprintf( result->value, "%ld", line_write ) ;
             else
                sprintf( result->value, "%ld", (long)line_write ) ;
 #endif
@@ -4463,7 +4465,7 @@ static streng *getrexxstatus( const tsd_t *TSD, cfileb
 #else
    if ( sizeof(rx_64) > 4 )
       sprintf( result->value + strlen(result->value),
-            " READ: char=%lld line=%lld WRITE: char=%lld line=%lld %s",
+            " READ: char=%ld line=%ld WRITE: char=%ld line=%ld %s",
             (ptr->readpos+1), ptr->readline,
             (ptr->writepos+1), ptr->writeline,
             (ptr->flag & FLAG_PERSIST) ? "PERSISTENT" : "TRANSIENT" ) ;
@@ -4851,7 +4853,7 @@ static streng *getseek( tsd_t *TSD, const streng *file
       sprintf(result->value, "%I64u", pos );
 #else
       if ( sizeof(rx_64) > 4 )
-         sprintf(result->value, "%lld", pos );
+         sprintf(result->value, "%ld", pos );
       else
          sprintf(result->value, "%ld", (long)pos );
 #endif
@@ -6079,7 +6081,7 @@ static streng *get_external_routine_file( const tsd_t 
    if ( *fp == NULL )
       return NULL;
 
-   my_fullpath( TSD, buf, inname );
+   my_fullpath( (tsd_t *) TSD, buf, inname );
 
    return Str_crestrTSD( buf );
 }
@@ -6717,7 +6719,7 @@ int my_fullpathstreng( const tsd_t *TSD, char *dst, co
    int retval;
 
    copy = str_ofTSD( src );
-   retval = my_fullpath( TSD, dst, copy );
+   retval = my_fullpath( (tsd_t *) TSD, dst, copy );
    FreeTSD( copy );
 
    return retval;
