--- registryd/registry-main.c.orig	2010-09-09 02:51:14 UTC
+++ registryd/registry-main.c
@@ -198,6 +198,7 @@ main (int argc, char **argv)
    * has been set.  If we have not been relocated, we will exit if the
    * at-spi-dbus key has been set.
    */
+  g_type_init ();
   gconf_client = gconf_client_get_default ();
 #ifdef RELOCATE
   need_to_quit = !gconf_client_get_bool (gconf_client, CORBA_GCONF_KEY, NULL);
