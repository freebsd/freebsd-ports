--- rt_cfg.c.orig	Wed Feb 18 08:55:40 2004
+++ rt_cfg.c	Wed Feb 18 08:57:03 2004
@@ -1047,11 +1047,11 @@
    byte * vendor;
    char filename[ 128 ];
 #if (SHAREWARE==1)
- VENDORDOC=("VENDOR.DOC");
- VENDORLUMP=("VENDOR");
+ const char *VENDORDOC=("VENDOR.DOC");
+ const char *VENDORLUMP=("VENDOR");
 #else
- VENDORDOC ("LICENSE.DOC");
- VENDORLUMP ("LICENSE");
+ const char *VENDORDOC=("LICENSE.DOC");
+ const char *VENDORLUMP=("LICENSE");
 #endif
 
 
