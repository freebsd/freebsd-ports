--- client/client.h.orig	2010-05-09 09:20:28 UTC
+++ client/client.h
@@ -136,8 +136,6 @@ struct localent_s
 //yummmm splash gibs death blood
 #define MAX_LOCAL_ENTS 1024
 
-localent_t cl_localents[MAX_LOCAL_ENTS];
-
 void Le_Reset (void);
 
 #ifdef USE_CURL
