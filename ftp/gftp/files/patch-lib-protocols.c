--- lib/protocols.c.orig	2008-12-04 21:35:37.000000000 +0100
+++ lib/protocols.c	2008-12-04 21:36:25.000000000 +0100
@@ -457,6 +457,7 @@
           fle->file = tmpfile;
         }
 
+#if GLIB_MAJOR_VERSION > 1
       if (ret >= 0 && fle->file != NULL)
         {
           if (g_utf8_validate (fle->file, -1, NULL))
@@ -472,6 +473,7 @@
                 }
             }
         }
+#endif
 
       if (ret >= 0 && !request->cached && request->cachefd > 0 && 
           request->last_dir_entry != NULL)
