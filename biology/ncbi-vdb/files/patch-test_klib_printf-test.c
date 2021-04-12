--- test/klib/printf-test.c.orig	2019-08-20 18:27:10 UTC
+++ test/klib/printf-test.c
@@ -503,7 +503,7 @@ rc_t run ( const char *progname )
         if ( rc == 0 )
         {
             rc = make_initial_test ( field_width, precision, " ", "s", "Kurt is having a fit" );
-#if !defined(__SunOS)  &&  !defined(__sun__)
+#if !defined(__SunOS)  &&  !defined(__sun__) && !defined(__FreeBSD__)
             /* Solaris printf doesn't cope with NULLs */
             rc = make_initial_test ( field_width, precision, " ", "s", NULL );
 #endif            
