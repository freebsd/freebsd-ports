--- src/common/config/config.c.orig	Mon Nov  4 01:34:37 2002
+++ src/common/config/config.c	Tue May  4 17:12:15 2004
@@ -407,11 +407,11 @@
 	configLoaded = 1;
 	if (file)
 	{
-		snprintf(buf,sizeof(buf),"%s/%s", INST_DIR, file);
+		snprintf(buf,sizeof(buf),"%s/etc/msql3/%s", INST_DIR, file);
 		fp = fopen(buf,"r");
 		if (!fp)
 		{
-			snprintf(buf,sizeof(buf),"%s/%s.conf",INST_DIR,file);
+			snprintf(buf,sizeof(buf),"%s/etc/msql3/%s.conf",INST_DIR,file);
 			fp = fopen(buf,"r");
 		}
 		if (!fp)
@@ -425,7 +425,7 @@
 	}
 	else
 	{
-		snprintf(buf,sizeof(buf),"%s/msql.conf", INST_DIR);
+		snprintf(buf,sizeof(buf),"%s/etc/msql3/msql.conf", INST_DIR);
 		fp = fopen(buf,"r");
 	}
 
