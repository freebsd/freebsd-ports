--- sysintf.c.orig	Thu Feb  2 05:39:56 2006
+++ sysintf.c	Mon May  1 18:33:02 2006
@@ -596,13 +596,12 @@
    if( tmpdir == NIL(char) )
       tmpdir = "/tmp";
 
-   while( --tries )
-   {
+   do {
       if( (fd = Create_temp(tmpdir, path, suff)) != -1)
          break;
 
       free(*path);
-   }
+   } while( --tries ); 
 
    if( fd != -1)
    {
@@ -839,8 +838,9 @@
       }
 
       if( Verbose & V_MAKE )
-	 printf( "%s:  <<<< Set [%s] time stamp to %lu\n",
-		 Pname, tcp->CE_NAME, tcp->ce_time );
+        printf( "%s:  <<<< Set [%s] time stamp to %llu\n",
+                Pname, tcp->CE_NAME, (unsigned long long)tcp->ce_time );
+
 
       if( Measure & M_TARGET )
 	 Do_profile_output( "e", M_TARGET, tcp );
