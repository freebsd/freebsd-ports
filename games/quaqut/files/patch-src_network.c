--- src/network.c.orig	2023-04-13 09:01:58 UTC
+++ src/network.c
@@ -22,6 +22,8 @@
 #include "quaqut.h"
 #include "protocol.h"
 
+struct quaqut quaqut;
+
 #ifdef _WIN_32_
   void quaqut_network_initwsa( void );
   void quaqut_network_shutwsa( void );
