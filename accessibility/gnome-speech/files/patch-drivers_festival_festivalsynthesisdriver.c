--- drivers/festival/festivalsynthesisdriver.c.orig	Tue Jan 11 14:48:51 2005
+++ drivers/festival/festivalsynthesisdriver.c	Tue Jan 11 14:50:22 2005
@@ -33,6 +33,8 @@
 #include <stdlib.h>
 #include <libbonobo.h>
 #include <netdb.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include "festivalsynthesisdriver.h"
 #include "festivalspeaker.h"
 
@@ -591,8 +593,8 @@
 static void
 voice_list_free (GSList *l)
 {
-	g_assert (l);
 	GSList *tmp = l;
+	g_assert (l);
 	
 	while (tmp)
 	{
