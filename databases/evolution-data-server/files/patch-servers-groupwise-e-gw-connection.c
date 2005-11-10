--- servers/groupwise/e-gw-connection.c.orig	Mon Oct  3 11:05:51 2005
+++ servers/groupwise/e-gw-connection.c	Thu Nov 10 00:32:44 2005
@@ -1979,8 +1979,8 @@
 	EGwConnectionPrivate *priv;
         SoupSoapParameter *param, *subparam, *second_level_child;
 	char *id, *name;
-        g_return_val_if_fail (E_IS_GW_CONNECTION (cnc), E_GW_CONNECTION_STATUS_INVALID_OBJECT);
 	static GStaticMutex connecting = G_STATIC_MUTEX_INIT;
+        g_return_val_if_fail (E_IS_GW_CONNECTION (cnc), E_GW_CONNECTION_STATUS_INVALID_OBJECT);
 
 	priv = cnc->priv;
 	g_static_mutex_lock (&connecting);
