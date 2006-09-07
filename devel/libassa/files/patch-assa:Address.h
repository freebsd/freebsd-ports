--- assa/Address.h.orig	Wed Sep  6 16:13:45 2006
+++ assa/Address.h	Wed Sep  6 16:13:57 2006
@@ -13,7 +13,6 @@
 #define ADDRESS_H
 
 #if !defined (WIN32)
-#  include <netinet/in.h>
 #  include <netdb.h>
 #  include <sys/types.h>
 #  include <sys/socket.h>
