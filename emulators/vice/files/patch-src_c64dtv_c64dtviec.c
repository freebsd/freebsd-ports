--- src/c64dtv/c64dtviec.c.orig	2024-12-24 19:12:44 UTC
+++ src/c64dtv/c64dtviec.c
@@ -113,6 +113,7 @@ void plus4tcbm_update_pc(uint8_t byte, unsigned int dn
 {
 }
 
+#if 0
 void parallel_cable_drive_write(int port, uint8_t data, int handshake, unsigned int dnr)
 {
 }
@@ -121,3 +122,4 @@ uint8_t parallel_cable_drive_read(int port, int handsh
 {
     return 0;
 }
+#endif
