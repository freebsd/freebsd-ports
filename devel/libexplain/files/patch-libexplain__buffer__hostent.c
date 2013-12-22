--- ./libexplain/buffer/hostent.c.orig	2013-03-15 02:34:07.000000000 +0100
+++ ./libexplain/buffer/hostent.c	2013-05-31 10:52:55.842570569 +0200
@@ -18,6 +18,7 @@
 
 #include <libexplain/ac/netdb.h>
 #include <libexplain/ac/string.h>
+#include <libexplain/ac/sys/socket.h>
 
 #include <libexplain/buffer/address_family.h>
 #include <libexplain/buffer/hexdump.h>
