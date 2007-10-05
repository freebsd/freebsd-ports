--- biewlib/twin.c.orig	2007-10-04 15:13:06.000000000 +0200
+++ biewlib/twin.c	2007-10-04 15:13:33.000000000 +0200
@@ -1891,9 +1891,9 @@
        strcpy(__nls,str);
        __nls_OemToOsdep((unsigned char *)__nls,len);
      }
-     else (const char *)__nls = str;
+     else __nls = str;
   }
-  else (const char *)__nls = str;
+  else __nls = str;
   __nls_ptr = __nls;
   __oem_ptr = str;
   vidx = active->cur_x + active->cur_y*active->wwidth;
