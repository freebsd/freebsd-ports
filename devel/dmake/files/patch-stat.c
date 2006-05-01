--- stat.c.orig	Mon May  1 18:23:40 2006
+++ stat.c	Mon May  1 18:25:04 2006
@@ -139,8 +139,8 @@
       }
 
       if( Verbose & V_MAKE )
-	 printf( "%s:  Checking library '%s' for member [%s], time %ld\n",
-		 Pname, cp->ce_lib, name, cp->ce_time );
+        printf( "%s:  Checking library '%s' for member [%s], time %llu\n",
+                Pname, cp->ce_lib, name, (unsigned long long)cp->ce_time );
    }
 
    FREE( tmp );
