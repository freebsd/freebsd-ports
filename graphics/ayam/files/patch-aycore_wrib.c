--- aycore/wrib.c.orig	2007-12-17 18:35:09.000000000 +0100
+++ aycore/wrib.c	2007-12-17 18:36:12.000000000 +0100
@@ -1158,7 +1158,7 @@
  size_t filenlen = 0;
  RtLightHandle light_handle;
  char arrname[] = "ayprefs", ccvarname[] = "SMChangeShaders";
- char *vstr = NULL;
+ const char *vstr;
  int changeshaders = AY_TRUE;
 
   if(!o || !file)
