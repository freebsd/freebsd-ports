--- smf/SMFHead.h.orig	2013-09-24 09:15:40.000000000 +0200
+++ smf/SMFHead.h	2013-09-24 09:15:50.000000000 +0200
@@ -34,10 +34,10 @@
 extern "C" {
 #include <tcl.h>
 }
-#include <iostream.h>
+#include <iostream>
 
 class SMFHead {
-	friend ostream &operator<<(ostream &os, const SMFHead &h);
+	friend std::ostream &operator<<(std::ostream &os, const SMFHead &h);
 public:
 	SMFHead();
 	SMFHead(short form, short num, short div);
