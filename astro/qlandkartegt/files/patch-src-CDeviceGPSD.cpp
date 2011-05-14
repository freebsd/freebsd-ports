Index: src/CDeviceGPSD.cpp
===================================================================
--- src/CDeviceGPSD.cpp	(revision 2719)
+++ src/CDeviceGPSD.cpp	(working copy)
@@ -138,6 +138,7 @@
 log_mutex( new QMutex() ),
 pipe_fd( _pipe_fd )
 {
+    gpsdata = NULL;
 }
 
 
@@ -149,7 +150,14 @@
 
 void CGPSDThread::run()
 {
+#if GPSD_API_MAJOR_VERSION >= 5
+	int socket;
+   
+    if( gpsdata = new gps_data_t )
+        socket = gps_open( "localhost", DEFAULT_GPSD_PORT, gpsdata );
+#else
     gpsdata = gps_open( "localhost", DEFAULT_GPSD_PORT );
+#endif
     if( !gpsdata )
     {
         // TODO: message box (from other thread)
@@ -187,13 +195,20 @@
             }                    // if
             else if( FD_ISSET( gpsdata->gps_fd, &fds ) )
             {
+#if GPSD_API_MAJOR_VERSION >= 5
+                gps_read( gpsdata );
+#else
                 gps_poll( gpsdata );
+#endif
                 if( !decodeData() ) break;
             }                    // else if
         }                        // else if
     }                            // while
 
     gps_close( gpsdata );
+#if GPSD_API_MAJOR_VERSION >= 5
+    delete gpsdata;
+#endif
     qDebug() << "thread done";
 }
