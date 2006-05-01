--- make.c.orig	Mon May  1 18:43:36 2006
+++ make.c	Mon May  1 18:45:08 2006
@@ -341,8 +341,9 @@
 	    }
 	       
 	    if( Verbose & V_MAKE )
-	       printf("%s:  Time stamp of [%s] is %ld\n",Pname,tcp->CE_NAME,
-		      tcp->ce_time);
+              printf("%s:  Time stamp of [%s] is %llu\n",Pname,tcp->CE_NAME,
+                     (unsigned long long)tcp->ce_time);
+
 	 }
       }
    }
