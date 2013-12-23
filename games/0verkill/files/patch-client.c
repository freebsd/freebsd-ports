--- client.c.orig	2001-12-16 12:26:38.000000000 +0300
+++ client.c	2013-11-17 11:40:44.755218781 +0400
@@ -191,9 +191,9 @@
 	unsigned char txt[256];
 
 #ifndef WIN32
-	sprintf(txt,"%s/%s",getenv("HOME"),CFG_FILE);
+	snprintf(txt,sizeof(txt),"%s/%s",getenv("HOME"),CFG_FILE);
 #else
-	sprintf(txt,"./%s",CFG_FILE);
+	snprintf(txt,sizeof(txt),"./%s",CFG_FILE);
 #endif
 	stream=fopen(txt,"r");
 	if (!stream)return;
@@ -223,9 +223,9 @@
 	unsigned char txt[256];
 
 #ifndef WIN32
-	sprintf(txt,"%s/%s",getenv("HOME"),CFG_FILE);
+	snprintf(txt,sizeof(txt),"%s/%s",getenv("HOME"),CFG_FILE);
 #else
-	sprintf(txt,"./%s",CFG_FILE);
+	snprintf(txt,sizeof(txt),"./%s",CFG_FILE);
 #endif
 	stream=fopen(txt,"w");
 	if (!stream)return;
