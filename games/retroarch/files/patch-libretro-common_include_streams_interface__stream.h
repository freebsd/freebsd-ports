--- libretro-common/include/streams/interface_stream.h.orig	2016-05-02 20:17:12 UTC
+++ libretro-common/include/streams/interface_stream.h
@@ -29,6 +29,8 @@
 #include <retro_common_api.h>
 #include <boolean.h>
 
+#include <sys/types.h>
+
 enum intfstream_type
 {
    INTFSTREAM_FILE = 0,
