--- src/game/network.c.orig	2010-12-22 19:26:01 UTC
+++ src/game/network.c
@@ -173,7 +173,7 @@ void close_session()
 
             for ( i = 0; i < numPeers; i++ )
             {
-#if defined(ENET11)
+#if 1
                 enet_peer_disconnect( &net_myHost->peers[i], 0 );
 #else
                 enet_peer_disconnect( &net_myHost->peers[i] );
@@ -1519,7 +1519,7 @@ void listen_for_packets()
                     // don't allow anyone to connect during the game session
                     log_warning( "listen_for_packets: Client tried to connect during the game: %x:%u\n",
                                  event.peer->address.host, event.peer->address.port );
-#if defined(ENET11)
+#if 1
                     enet_peer_disconnect( event.peer, 0 );
 #else
                     enet_peer_disconnect( event.peer );
@@ -1845,7 +1845,7 @@ int cl_joinGame( const char* hostname )
         log_info( "cl_joinGame: Creating client network connection... " );
         // Create my host thingamabober
         /// @todo Should I limit client bandwidth here?
-        net_myHost = enet_host_create( NULL, 1, 0, 0 );
+        net_myHost = enet_host_create( NULL, 1, 0, 0, 0 );
         if ( NULL == net_myHost )
         {
             // can't create a network connection at all
@@ -1861,7 +1861,7 @@ int cl_joinGame( const char* hostname )
         log_info( "cl_joinGame: Attempting to connect to %s:%d\n", hostname, NET_EGOBOO_PORT );
         enet_address_set_host( &address, hostname );
         address.port = NET_EGOBOO_PORT;
-        net_gameHost = enet_host_connect( net_myHost, &address, NET_EGOBOO_NUM_CHANNELS );
+        net_gameHost = enet_host_connect( net_myHost, &address, NET_EGOBOO_NUM_CHANNELS, 0 );
         if ( NULL == net_gameHost )
         {
             log_info( "cl_joinGame: No available peers to create a connection!\n" );
@@ -1904,7 +1904,7 @@ int sv_hostGame()
         address.port = NET_EGOBOO_PORT;
 
         log_info( "sv_hostGame: Creating game on port %d\n", NET_EGOBOO_PORT );
-        net_myHost = enet_host_create( &address, MAX_PLAYER, 0, 0 );
+        net_myHost = enet_host_create( &address, MAX_PLAYER, 0, 0, 0 );
         if ( NULL == net_myHost )
         {
             log_info( "sv_hostGame: Could not create network connection!\n" );
@@ -2180,4 +2180,4 @@ player_t* chr_get_ppla( const CHR_REF ichr )
     if ( !VALID_PLA( iplayer ) ) return NULL;
 
     return PlaStack.lst + iplayer;
-}
\ No newline at end of file
+}
