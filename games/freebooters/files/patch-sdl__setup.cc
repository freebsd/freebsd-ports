
$FreeBSD$

--- sdl_setup.cc.orig	Thu Sep 30 00:32:24 2004
+++ sdl_setup.cc	Thu Sep 30 00:39:30 2004
@@ -59,7 +59,7 @@
    int audio_buffers = 4096;
 
 
-   readdata config("/etc/freebooters.conf");
+   readdata config("%%PREFIX%%/etc/freebooters.conf");
 
    if (config.get_str("sound") != "no")
    {
