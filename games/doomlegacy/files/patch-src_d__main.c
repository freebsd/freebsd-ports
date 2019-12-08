--- src/d_main.c.orig	2018-07-25 10:14:34 UTC
+++ src/d_main.c
@@ -454,18 +454,20 @@ void  owner_wad_search_order( void )
         }
         else
         if(    (strcmp( defdir, cv_home.string ) != 0) // not home directory
-	    && (strcmp( defdir, progdir ) != 0)        // not program directory
-            && (strcmp( defdir, progdir_wads ) != 0) ) // not wads directory
-        {
+          ) { if( verbose )
+                GenPrintf( EMSG_ver, "User's home is default dir, not searched.\n");
+        } else {
             defdir_search = 1;
             // Search current dir near first, for other wad searches.
             doomwaddir[1] = defdir;
 	}
     }
+#if 0 // only useful for developers, missing NULL checks
     // Search progdir/wads early, for other wad searches.
     doomwaddir[2] = progdir_wads;
     // Search last, for other wad searches.
     doomwaddir[MAX_NUM_DOOMWADDIR-1] = progdir;
+#endif
 }
 
 
