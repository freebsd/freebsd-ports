--- src/sj-prefs.c.orig	Tue Jan 20 22:45:59 2004
+++ src/sj-prefs.c	Wed Jan 21 14:38:24 2004
@@ -75,7 +75,6 @@
       CDDrive *cdrom = cdroms->data;
       cd_drive_free (cdrom);
       cdroms = g_list_remove (cdroms, cdrom);
-      g_free (cdrom);    
     }
   }
   return default_device;
