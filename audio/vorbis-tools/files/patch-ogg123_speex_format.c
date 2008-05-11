--- ogg123/speex_format.c.orig	2008-05-11 17:57:48.000000000 +0200
+++ ogg123/speex_format.c	2008-05-11 17:58:19.000000000 +0200
@@ -475,7 +475,7 @@ void *process_header(ogg_packet *op, int
            cb->printf_error(callback_arg, ERROR, _("Cannot read header"));
      return NULL;
    }
-   if ((*header)->mode >= SPEEX_NB_MODES) {
+   if ((*header)->mode >= SPEEX_NB_MODES || (*header)->mode < 0) {
      cb->printf_error(callback_arg, ERROR, 
 		      _("Mode number %d does not (any longer) exist in this version"),
 	      (*header)->mode);
