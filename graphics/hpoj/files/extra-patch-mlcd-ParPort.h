--- mlcd/ParPort.h.orig	Sat May 24 08:02:19 2003
+++ mlcd/ParPort.h	Sat May 24 07:59:13 2003
@@ -27,6 +27,11 @@
 
 #define ERROR_NO_DATA ERROR	/* TODO: Remove. */
 
+extern "C" {
+extern u_char inb (u_int port);
+extern void outb(u_int port, u_char data);
+}
+
 class ParPort {
     protected:		// ATTRIB
 	int portType;
