--- src/orpheusconf.cc	Sat Feb 14 20:11:05 2004
+++ src/orpheusconf.cc	Sun Dec 12 16:03:16 2004
@@ -34,7 +34,7 @@
 
 OrpheusConfiguration::OrpheusConfiguration()
     : dname((string) getenv("HOME") + "/.orpheus"),
-      oggplayer("ogg123 -v"), cddev("/dev/cdrom"),
+      oggplayer("ogg123 -v"), cddev("/cdrom"),
       mixerdev("/dev/mixer"), cdautofetch(true), russian(false),
       autosavepl(false), autoplay(true), playmode(Normal),
       sortorder(noSort), sortasc(true)
