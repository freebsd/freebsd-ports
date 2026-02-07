--- libretro-common/cdrom/cdrom.c.orig	2020-03-17 23:29:26 UTC
+++ libretro-common/cdrom/cdrom.c
@@ -478,6 +478,8 @@ static int cdrom_send_command(libretro_vfs_implementat
 #endif
 
 retry:
+#if defined(__linux_) || defined(_WIN32)
+
 #if defined(__linux__) && !defined(ANDROID)
       if (cached_read || !cdrom_send_command_linux(stream, dir, xfer_buf_pos, request_len, cmd, cmd_len, sense, sizeof(sense)))
 #else
@@ -518,6 +520,7 @@ retry:
          }
       }
       else
+#endif
       {
          cdrom_print_sense_data(sense, sizeof(sense));
 
