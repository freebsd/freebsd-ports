--- ./src/plugins/positionprovider/gpsd/GpsdConnection.cpp.orig	2011-03-22 18:32:49.000000000 +0300
+++ ./src/plugins/positionprovider/gpsd/GpsdConnection.cpp	2011-03-22 19:24:18.000000000 +0300
@@ -18,7 +18,8 @@
 
 GpsdConnection::GpsdConnection( QObject* parent )
     : QObject( parent ),
-      m_timer( 0 )
+      m_timer( 0 ),
+      m_gpsd("localhost", DEFAULT_GPSD_PORT)
 {
     connect( &m_timer, SIGNAL( timeout() ), this, SLOT( update() ) );
 }
@@ -26,15 +27,15 @@
 void GpsdConnection::initialize()
 {
     m_timer.stop();
-    gps_data_t* data = m_gpsd.open();
-    if ( data ) {
+#if 0	/* I don't see error handling in the new libgpsmm API */
+    if ( m_gpsd.to_user != NULL ) {
+#endif
         m_status = PositionProviderStatusAcquiring;
         emit statusChanged( m_status );
 
-#if defined( GPSD_API_MAJOR_VERSION ) && ( GPSD_API_MAJOR_VERSION >= 3 ) && defined( WATCH_ENABLE )
         m_gpsd.stream( WATCH_ENABLE );
-#endif
         m_timer.start( 1000 );
+#if 0
     }
     else {
         // There is also gps_errstr() for libgps version >= 2.90,
@@ -68,28 +69,17 @@
 
         mDebug() << "Connection to gpsd failed, no position info available: " << m_error;
     }
+#endif
 }
 
 void GpsdConnection::update()
 {
-#if defined( GPSD_API_MAJOR_VERSION ) && ( GPSD_API_MAJOR_VERSION >= 3 ) && defined( PACKET_SET )
-    if ( m_gpsd.waiting() ) {
-        gps_data_t* data = m_gpsd.poll();
+    if ( m_gpsd.waiting(5000000) ) {
+        gps_data_t* data = m_gpsd.read();
         if ( data && data->set & PACKET_SET ) {
             emit gpsdInfo( *data );
         }
     }
-#else
-    gps_data_t* data = m_gpsd.query( "o" );
-
-    if ( data ) {
-        emit gpsdInfo( *data );
-    }
-    else if ( m_status != PositionProviderStatusAcquiring ) {
-        mDebug() << "Lost connection to gpsd, trying to re-open.";
-        initialize();
-    }
-#endif
 }
 
 QString GpsdConnection::error() const
