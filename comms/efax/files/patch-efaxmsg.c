--- efaxmsg.c.orig	1999-03-20 04:38:20 UTC
+++ efaxmsg.c
@@ -98,9 +98,6 @@ int msg ( char *fmt, ... ) 
   int err=0, i, flags=0 ;
   char *p ;
   
-  va_list ap ;
-  va_start ( ap, fmt ) ;
-
   if ( ! init ) {
     logfile[0] = stderr ;
     logfile[1] = stdout ;
@@ -112,6 +109,9 @@ int msg ( char *fmt, ... ) 
   
   for ( i=0 ; i<NLOG ; i++ ) {
 
+    va_list ap ;
+    va_start ( ap, fmt ) ;
+
     for ( p=fmt ; *p ; p++ ) {
       switch ( *p ) {
       case ' ': p++ ; goto print ;
@@ -148,11 +148,11 @@ int msg ( char *fmt, ... ) 
       if ( ! ( flags & NOFLSH ) ) fflush ( logfile[i] ) ;
       
     }
+  
+    va_end ( ap ) ;
     
   }
   
-  va_end ( ap ) ;
-  
   return err ;
 }
 
