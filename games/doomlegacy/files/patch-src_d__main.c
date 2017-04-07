--- src/d_main.c.orig	2017-03-03 19:49:10 UTC
+++ src/d_main.c
@@ -439,11 +439,13 @@ extern char mac_user_home[FILENAME_SIZE]
 void  owner_wad_search_order( void )
 {
     // Wad search order.
+#if 0
     if( defdir_stat )
     {
         // Search current dir near first, for other wad searches.
         doomwaddir[1] = defdir;
     }
+#endif
     // Search progdir/wads early, for other wad searches.
     doomwaddir[2] = progdir_wads;
     // Search last, for other wad searches.
@@ -1160,8 +1162,10 @@ void  Print_search_directories( byte emf
     // Verbose only. For IWAD or legacy.wad they are in doomwaddir entries.
     if( (enables==0x0F) && progdir_wads )
         GenPrintf(emf, "        : %s\n", progdir_wads );
+#if 0
     if( (enables==0x0F) && defdir )
         GenPrintf(emf, " defdir: %s\n", defdir );
+#endif
 #ifdef LEGACYWADDIR
     GenPrintf(emf, " LEGACYWADDIR: %s\n", LEGACYWADDIR );
 #endif
