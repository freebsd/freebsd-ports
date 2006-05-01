--- bonobo-activation/bonobo-activation-fork-server.c.orig	Fri Sep  9 17:20:15 2005
+++ bonobo-activation/bonobo-activation-fork-server.c	Fri Sep  9 17:31:52 2005
@@ -359,10 +359,18 @@
                 g_source_destroy (source);
                 g_source_unref (source);
                 
+                g_io_channel_shutdown (ai.ioc, FALSE, NULL);
                 g_io_channel_unref (ai.ioc);
                 
                 if (use_new_loop)
                         g_main_context_unref (context);
+
+                close (iopipes[1]);
+
+                g_strfreev(newenv);
+
+                if (fd_arg != 0)
+                        g_free ((char *) cmd[fd_arg]);
 
 		return CORBA_OBJECT_NIL;
 	}
