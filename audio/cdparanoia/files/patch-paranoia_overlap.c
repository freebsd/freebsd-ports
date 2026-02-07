--- paranoia/overlap.c.orig	2019-07-23 18:06:02 UTC
+++ paranoia/overlap.c
@@ -107,7 +107,7 @@ void offset_adjust_settings(cdrom_paranoia *p, void(*c
        sector, frob it.  We just want a little hysteresis [sp?]*/
     long av=(p->stage2.offpoints?p->stage2.offaccum/p->stage2.offpoints:0);
     
-    if(abs(av)>p->dynoverlap/4){
+    if(labs(av)>p->dynoverlap/4){
       av=(av/MIN_SECTOR_EPSILON)*MIN_SECTOR_EPSILON;
       
       if(callback)(*callback)(ce(p->root.vector),PARANOIA_CB_DRIFT);
@@ -207,7 +207,7 @@ void offset_add_value(cdrom_paranoia *p,offsets *o,lon
   if(o->offpoints!=-1){
 
     /* Track the average magnitude of jitter (in either direction) */
-    o->offdiff+=abs(value);
+    o->offdiff+=labs(value);
     o->offpoints++;
     o->newpoints++;
 
