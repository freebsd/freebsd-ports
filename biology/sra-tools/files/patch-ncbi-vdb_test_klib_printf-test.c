--- ncbi-vdb/test/klib/printf-test.c.orig	2023-07-10 16:13:36 UTC
+++ ncbi-vdb/test/klib/printf-test.c
@@ -504,7 +504,7 @@ rc_t run ( const char *progname )
         if ( rc == 0 )
         {
             rc = make_initial_test ( field_width, precision, " ", "s", "Kurt is having a fit" );
-#if !defined(__SunOS)  &&  !defined(__sun__)
+#if !defined(__SunOS)  &&  !defined(__sun__) && !defined(__FreeBSD__)
             /* Solaris printf doesn't cope with NULLs */
 #if 0
             /* The standard says this result is undefined, we shouldn't test for it, it is not consistent */
