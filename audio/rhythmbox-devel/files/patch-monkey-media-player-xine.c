--- monkey-media/monkey-media-player-xine.c.orig	Wed Sep  3 14:30:52 2003
+++ monkey-media/monkey-media-player-xine.c	Wed Sep  3 14:32:41 2003
@@ -520,8 +520,10 @@
 		if (xine_get_param (mp->priv->stream, XINE_PARAM_SPEED) == XINE_SPEED_NORMAL)
 			xine_set_param (mp->priv->stream, XINE_PARAM_SPEED, XINE_SPEED_PAUSE);
 
+#ifdef HAVE_XINE_CLOSE
 		/* Close the audio device when on pause */
 		xine_set_param (mp->priv->stream, XINE_PARAM_AUDIO_CLOSE_DEVICE, 1);
+#endif
 	}
 
 	mp->priv->timer_add += floor (g_timer_elapsed (mp->priv->timer, NULL) + 0.5);
