diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ ddup.h.orig ddup.h
--- ddup.h.orig	Tue Oct 31 01:09:48 2000
+++ ddup.h	Mon Jul 22 21:51:52 2002
@@ -5,7 +5,7 @@
 #include "options.h"
 
 #define AGENT_NAME "ddup"
-#define AGENT_VER "3.0.1"
+#define AGENT_VER "3.0.1.1"
 #define MEMBERS_HOST "members.dyndns.org"
 
 /* ddup_functions.c */
