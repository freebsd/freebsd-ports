$OpenBSD: patch-src_plugins_sndio_ao_sndio_c,v 1.3 2014/05/27 19:44:56 naddy Exp $
--- src/plugins/sndio/ao_sndio.c.orig	2012-02-14 00:46:06 UTC
+++ src/plugins/sndio/ao_sndio.c
@@ -99,6 +99,7 @@ int ao_plugin_set_option(ao_device *devi
 int ao_plugin_open(ao_device *device, ao_sample_format *format)
 {
   ao_sndio_internal *internal = (ao_sndio_internal *) device->internal;
+  struct sio_hdl *hdl;
   struct sio_par par;
 
   if(!internal->dev && internal->id>=0){
@@ -107,20 +108,26 @@ int ao_plugin_open(ao_device *device, ao
     internal->dev = strdup(buf);
   }
 
-  internal->hdl = sio_open(internal->dev, SIO_PLAY, 0);
-  if (internal->hdl == NULL)
+  hdl = sio_open(internal->dev, SIO_PLAY, 0);
+  if (hdl == NULL)
     return 0;
+  internal->hdl = hdl;
 
   sio_initpar(&par);
   par.sig = 1;
-  par.le = SIO_LE_NATIVE;
+  if (format->bits > 8)
+    par.le = device->client_byte_format == AO_FMT_LITTLE ? 1 : 0;
   par.bits = format->bits;
   par.rate = format->rate;
   par.pchan = device->output_channels;
-  if (!sio_setpar(internal->hdl, &par))
+  if (!sio_setpar(hdl, &par))
     return 0;
-  device->driver_byte_format = AO_FMT_NATIVE;
-  if (!sio_start(internal->hdl))
+  if (!sio_getpar(hdl, &par))
+    return 0;
+  if (par.bits != format->bits)
+    return 0;
+  device->driver_byte_format = par.le ? AO_FMT_LITTLE : AO_FMT_BIG;
+  if (!sio_start(hdl))
     return 0;
 
   if(!device->inter_matrix){
@@ -148,9 +155,10 @@ int ao_plugin_close(ao_device *device)
   ao_sndio_internal *internal = (ao_sndio_internal *) device->internal;
   struct sio_hdl *hdl = internal->hdl;
 
-  if(hdl)
-    if (!sio_stop(hdl))
-      return 0;
+  if(hdl){
+    sio_close(hdl);
+    internal->hdl = NULL;
+  }
   return 1;
 }
 
