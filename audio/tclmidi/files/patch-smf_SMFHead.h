--- smf/SMFHead.h.orig	1996-08-05 03:47:35 UTC
+++ smf/SMFHead.h
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
