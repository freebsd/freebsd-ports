--- fceux-server/server.cpp.orig	2012-11-02 13:41:36 UTC
+++ fceux-server/server.cpp
@@ -114,7 +114,7 @@ int LoadConfigFile(char *fn)
  if(fp=fopen(fn,"rb"))
  {
   char buf[256];
-  while(fgets(buf, 256, fp) > 0)
+  while(fgets(buf, 256, fp))
   {
    if(!strncasecmp(buf,"maxclients",strlen("maxclients")))
     sscanf(buf,"%*s %d",&ServerConfig.MaxClients);
