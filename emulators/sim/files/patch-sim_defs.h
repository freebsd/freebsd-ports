--- sim_defs.h.orig	Thu May  2 18:23:02 2002
+++ sim_defs.h	Wed May 22 08:13:27 2002
@@ -319,7 +319,7 @@
 #define GRDATA(nm,loc,rdx,wd,pos) #nm, &(loc), (rdx), (wd), (pos), 1
 #define BRDATA(nm,loc,rdx,wd,dep) #nm, (loc), (rdx), (wd), 0, (dep)
 #define URDATA(nm,loc,rdx,wd,off,dep,fl) \
-	#nm, &(loc), (rdx), (wd), (off), (dep), ((fl) | REG_UNIT)
+	"nm", &(loc), (rdx), (wd), (off), (dep), ((fl) | REG_UNIT)
 #else
 #define ORDATA(nm,loc,wd) "nm", &(loc), 8, (wd), 0, 1
 #define DRDATA(nm,loc,wd) "nm", &(loc), 10, (wd), 0, 1
