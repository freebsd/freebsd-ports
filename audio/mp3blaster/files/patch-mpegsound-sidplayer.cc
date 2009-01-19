--- mpegsound/sidplayer.cc.orig	2009-01-19 22:40:25.000000000 +0300
+++ mpegsound/sidplayer.cc	2009-01-19 22:40:42.000000000 +0300
@@ -33,7 +33,7 @@
 	if (buffer) delete buffer;
 }
 
-bool SIDfileplayer::openfile(const char *filename, char *device, soundtype write2file)
+bool SIDfileplayer::openfile(const char *filename, const char *device, soundtype write2file)
 {
 	int ssize;
 
