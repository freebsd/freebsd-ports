--- app/CorePlayer.cpp-orig	Wed Jun 18 13:48:49 2003
+++ app/CorePlayer.cpp	Wed Jun 18 13:52:02 2003
@@ -1165,6 +1165,7 @@
 			//alsaplayer_error("producer: waiting for free buffer");
 			pthread_mutex_lock(&obj->counter_mutex);
 			//alsaplayer_error("producer: unblocked");
+			dosleep(1000);
 		}	
 	}
 	//alsaplayer_error("Exitting producer_func (producing = %d)", obj->producing);
