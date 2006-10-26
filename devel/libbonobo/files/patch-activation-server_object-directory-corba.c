--- activation-server/object-directory-corba.c.orig	Mon Aug 14 14:27:54 2006
+++ activation-server/object-directory-corba.c	Thu Oct 26 09:25:50 2006
@@ -732,8 +732,10 @@
                         g_object_set_data (
                                 G_OBJECT (cnx), "object_count", GUINT_TO_POINTER (1));
                         
-                        ORBit_small_listen_for_broken
-                                (object, G_CALLBACK (active_server_cnx_broken), NULL);
+                        g_signal_connect (
+                                cnx, "broken",
+                                G_CALLBACK (active_server_cnx_broken),
+                                NULL);
                 }
         } else
                 g_assert (!strcmp (iid, NAMING_CONTEXT_IID) ||
