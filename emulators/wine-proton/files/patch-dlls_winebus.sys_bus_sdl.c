--- dlls/winebus.sys/bus_sdl.c.orig
+++ dlls/winebus.sys/bus_sdl.c
@@ -1070,12 +1070,6 @@
         version = 0;
     }
 
-    if(is_already_opened_by_hidraw(vid, pid))
-    {
-        /* we use SDL only for controllers which hidraw couldn't open */
-        TRACE("device %04x/%04x already opened by hidraw, skipping\n", vid, pid);
-        return;
-    }
 
     if(is_in_sdl_blacklist(vid, pid))
     {
