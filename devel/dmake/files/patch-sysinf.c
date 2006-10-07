--- sysintf.c.orig	Sun Oct  8 00:23:30 2006
+++ sysintf.c	Sun Oct  8 00:23:30 2006
@@ -608,13 +608,12 @@
    if( tmpdir == NIL(char) )
       tmpdir = "/tmp";
 
-   while( --tries )
-   {
+   do {
       if( (fd = Create_temp(tmpdir, path)) != -1)
          break;
 
       free(*path); /* free var if creating temp failed. */
-   }
+   } while( --tries );
 
    if( fd != -1)
    {
@@ -881,8 +880,8 @@
       }
 
       if( Verbose & V_MAKE )
-	 printf( "%s:  <<<< Set [%s] time stamp to %lu\n",
-		 Pname, tcp->CE_NAME, tcp->ce_time );
+	 printf( "%s:  <<<< Set [%s] time stamp to %llu\n",
+		 Pname, tcp->CE_NAME, (unsigned long long)tcp->ce_time );
 
       if( Measure & M_TARGET )
 	 Do_profile_output( "e", M_TARGET, tcp );
