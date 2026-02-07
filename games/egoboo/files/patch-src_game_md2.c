--- src/game/md2.c.orig	2021-07-15 21:58:55 UTC
+++ src/game/md2.c
@@ -511,7 +511,7 @@ MD2_Model_t* md2_load( const char * szFilename, MD2_Mo
                 int i;
                 for ( i = 0; i < cmd->command_count; i++ )
                 {
-                    cmd->data[i].index = SDL_swap32( cmd->data[i].s );
+                    cmd->data[i].index = SDL_Swap32( cmd->data[i].s );
                     cmd->data[i].s     = ENDIAN_FLOAT( cmd->data[i].s );
                     cmd->data[i].t     = ENDIAN_FLOAT( cmd->data[i].t );
                 };
