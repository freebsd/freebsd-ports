--- support.c.orig	2008-03-30 09:31:55.000000000 -0400
+++ support.c	2008-05-14 08:05:30.000000000 -0400
@@ -4,7 +4,11 @@
 #include <signal.h>
 
 #ifdef BSD
+#ifdef OLDSPKR
+#include <machine/speaker.h>
+#else
 #include <dev/speaker/speaker.h>
+#endif
 #include "bsd_bells.c"
 #endif
 
@@ -1199,31 +1203,21 @@
 static gint get_running_pid(const gchar *filnam)
 {
   FILE *fp;
-  gchar filnam_hold[14], psc_line[81], system_line[41];
+  gchar psc_line[81], system_line[41];
   gint ami_running=-1;
 
-  strcpy(filnam_hold, filnam);
-  strcat(filnam_hold, ".tmp");
 #ifdef BSD
-  strcpy(system_line, "ps | grep ");
-  strcat(system_line, filnam);
-  strcat(system_line, " | grep -v grep > ");
-  strcat(system_line, filnam_hold);
+  sprintf(system_line, "ps | grep %s | grep -v grep", filnam);
 #else
-  strcpy(system_line, "ps -C ");
-  strcat(system_line, filnam);
-  strcat(system_line, " | sort > ");
-  strcat(system_line, filnam_hold);
+  sprintf(system_line, "ps -C | grep %s | sort", filnam);
 #endif
-  system(system_line);
-  fp = fopen(filnam_hold, "r");
+  fp = popen(system_line, "r");
   if(fp!=NULL)
    {
     fgets(psc_line, sizeof(psc_line), fp);
     if(kb_index (psc_line, filnam)>-1)
      ami_running = atoi(psc_line);
     fclose(fp);
-    remove(filnam_hold);
    }
   return ami_running;
 }
