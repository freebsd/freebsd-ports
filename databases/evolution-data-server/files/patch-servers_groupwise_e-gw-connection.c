--- servers/groupwise/e-gw-connection.c.orig	Tue Mar  8 03:50:29 2005
+++ servers/groupwise/e-gw-connection.c	Tue Mar  8 03:50:40 2005
@@ -1764,8 +1764,8 @@
 	EGwConnectionPrivate *priv;
         SoupSoapParameter *param, *subparam, *second_level_child;
 	char *id, *name;
-        g_return_val_if_fail (E_IS_GW_CONNECTION (cnc), E_GW_CONNECTION_STATUS_INVALID_OBJECT);
 	static GStaticMutex connecting = G_STATIC_MUTEX_INIT;
+        g_return_val_if_fail (E_IS_GW_CONNECTION (cnc), E_GW_CONNECTION_STATUS_INVALID_OBJECT);
 
 	priv = cnc->priv;
 	g_static_mutex_lock (&connecting);
