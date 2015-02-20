--- protos.h.orig	2015-02-14 01:31:41.352230000 +0100
+++ protos.h	2015-02-14 01:39:01.934630000 +0100
@@ -192,7 +192,7 @@
 
 // rendermd2
 extern void rendermodel(char *mdl, int frame, int range, int tex, float rad, float x, float y, float z, float yaw, float pitch, bool teammate, float scale, float speed, int snap = 0, int basetime = 0);
-extern mapmodelinfo &getmminfo(int i);
+extern mapmodelinfo *getmminfo(int i);
 
 // server
 extern void initserver(bool dedicated, int uprate, char *sdesc, char *ip, char *master, char *passwd, int maxcl);
