--- backend/kodakaio.c.orig	2012-08-10 09:33:29.000000000 +0900
+++ backend/kodakaio.c	2012-08-29 16:35:36.000000000 +0900
@@ -181,6 +181,10 @@
 #include <math.h>
 #include <poll.h>
 #include <time.h>
+#include <sys/types.h>
+#ifdef HAVE_SYS_SOCKET_H
+#include <sys/socket.h>
+#endif
 
 #if WITH_AVAHI
 /* used for auto detecting network printers  */
@@ -2184,6 +2188,7 @@
     AvahiLookupResultFlags flags,
     AVAHI_GCC_UNUSED void* userdata) {
 
+	AvahiStringList *vid_pair_list = NULL, *pid_pair_list = NULL;
 	char *pidkey, *pidvalue;
 	char *vidkey, *vidvalue;
 	size_t valuesize;
@@ -2204,20 +2209,40 @@
             avahi_address_snprint(a, sizeof(a), address);
 
 /* Output short for Kodak ESP */
-	DBG(min(10,DBG_AUTO), "%s:%u  %s  ", a,port,host_name);
-	avahi_string_list_get_pair(avahi_string_list_find(txt, "vid"), 
-		&vidkey, &vidvalue, &valuesize);
-	DBG(min(10,DBG_AUTO), "%s=%s  ", vidkey, vidvalue);
-	avahi_string_list_get_pair(avahi_string_list_find(txt, "pid"), 
-		&pidkey, &pidvalue, &valuesize);
-	DBG(min(10,DBG_AUTO), "%s=%s\n", pidkey, pidvalue);
+	DBG(min(10,DBG_AUTO), "%s:%u  %s\n", a,port,host_name);
+
+	vid_pair_list = avahi_string_list_find(txt, "vid");
+	if(vid_pair_list != NULL) {
+		avahi_string_list_get_pair(vid_pair_list, &vidkey, &vidvalue, &valuesize);
+		DBG(min(10,DBG_AUTO), "%s=%s  ", vidkey, vidvalue);
+	}
+	else	DBG(min(10,DBG_AUTO), "failed to find key vid\n");
 
+	pid_pair_list = avahi_string_list_find(txt, "pid");
+	if(pid_pair_list != NULL) {
+		avahi_string_list_get_pair(pid_pair_list, &pidkey, &pidvalue, &valuesize);
+		DBG(min(10,DBG_AUTO), "%s=%s\n", pidkey, pidvalue);
+	}
+	else	DBG(min(10,DBG_AUTO), "failed to find key pid\n");
+
+	if(pid_pair_list != NULL && vid_pair_list != NULL) {
 		ProcessAvahiDevice(name, vidvalue, pidvalue, a);
-	avahi_free(vidkey); avahi_free(vidvalue);
-	avahi_free(pidkey); avahi_free(pidvalue);
+	}
+	else DBG(min(10,DBG_AUTO), "didn't call ProcessAvahiDevice\n");
+
+	if(vid_pair_list != NULL) {
+		avahi_free(vidkey); 
+		avahi_free(vidvalue);
+		DBG(min(15,DBG_AUTO), "vidkey and vidvalue freed\n");
+	}
+	if(pid_pair_list != NULL) {
+		avahi_free(pidkey); 
+		avahi_free(pidvalue);
+		DBG(min(15,DBG_AUTO), "pidkey and pidvalue freed\n");
+	}
         }
     }
-
+    DBG(min(10,DBG_AUTO), "ending resolve_callback\n");
     avahi_service_resolver_free(r);
 }
 
