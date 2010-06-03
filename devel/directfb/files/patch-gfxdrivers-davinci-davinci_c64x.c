--- gfxdrivers/davinci/davinci_c64x.c
+++ gfxdrivers/davinci/davinci_c64x.c
@@ -57,6 +57,8 @@
 #define C64X_QLEN    direct_page_align( sizeof(c64xTaskControl) )
 #define C64X_MLEN    direct_page_align( 0x2000000 )
 
+typedef unsigned long ulong;
+
 __attribute__((noinline))
 static void
 davinci_c64x_queue_error( DavinciC64x *c64x, const char *msg )
