--- platform.mk.orig	2016-08-24 12:05:47 UTC
+++ platform.mk
@@ -49,7 +49,6 @@ else
             BINFLAGS += -pie
             LDFLAGS += -Wl,-z,relro,-z,now
         endif
-        LDFLAGS += -ldl
     endif
 endif
 
