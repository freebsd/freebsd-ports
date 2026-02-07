--- unzpriv.h.orig	2009-04-19 23:59:26 UTC
+++ unzpriv.h
@@ -3008,7 +3008,7 @@ char    *GetLoadPath     OF((__GPRO));  
          !(((islochdr) || (isuxatt)) && \
            ((hostver) == 25 || (hostver) == 26 || (hostver) == 40))) || \
         (hostnum) == FS_HPFS_ || \
-        ((hostnum) == FS_NTFS_ && (hostver) == 50)) { \
+        ((hostnum) == FS_NTFS_ /* && (hostver) == 50 */ )) { \
         _OEM_INTERN((string)); \
     } else { \
         _ISO_INTERN((string)); \
