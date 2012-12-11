Index: kioslave/smtp/command.h
diff -u kioslave/smtp/command.h.orig kioslave/smtp/command.h
--- kioslave/smtp/command.h.orig	2011-07-28 03:34:56.000000000 +0900
+++ kioslave/smtp/command.h	2012-12-11 15:39:27.661365803 +0900
@@ -33,6 +33,8 @@
 #define __KIOSMTP_COMMAND_H__
 
 
+#include <sys/types.h>
+
 extern "C" {
 #include <sasl/sasl.h>
 }
