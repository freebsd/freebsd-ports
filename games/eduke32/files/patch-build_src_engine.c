--- build/src/engine.c.orig	2015-09-23 17:55:31 UTC
+++ build/src/engine.c
@@ -5349,7 +5349,8 @@ static void drawalls(int32_t bunch)
             static char fn[32], tmpbuf[80];
             char purple = getclosestcol(255, 0, 255);
             char yellow = getclosestcol(255, 255, 0);
-            char *bakframe = (char *)Xaligned_alloc(16, xdim*ydim);
+	     char *bakframe;
+            posix_memalign(&bakframe, 16, xdim*ydim);
 
             begindrawing();  //{{{
             Bmemcpy(bakframe, (char *)frameplace, xdim*ydim);
@@ -8142,7 +8143,7 @@ static void dosetaspect(void)
         if (xdimen != oxdimen && voxoff[0][0])
         {
             if (distrecip == NULL)
-                distrecip = (uint32_t *)Xaligned_alloc(16, DISTRECIPSIZ * sizeof(uint32_t));
+                posix_memalign(&distrecip, 16, DISTRECIPSIZ * sizeof(uint32_t));
 
             if (xdimen < 1 << 11)
             {
@@ -11757,7 +11758,7 @@ static void initsmost(void)
     {
         Baligned_free(*dynarray[i].ptr);
 
-        *dynarray[i].ptr = Xaligned_alloc(16, dynarray[i].size);
+         posix_memalign(dynarray[i].ptr, 16, dynarray[i].size);
     }
 
     ysavecnt = YSAVES;
