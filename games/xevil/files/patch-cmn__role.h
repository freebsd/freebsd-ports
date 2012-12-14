--- cmn/role.h.orig	2012-05-27 06:52:31.000000000 +0900
+++ cmn/role.h	2012-05-27 06:53:11.000000000 +0900
@@ -539,7 +539,7 @@
 
 
 public:
-  Server(Boolean localHuman,char *portName,LocatorP);
+  Server(Boolean localHuman,const char *portName,LocatorP);
   /* EFFECTS: Create a server that listens for connections on given port.
      If NULL is passed in, use XETP::DEFAULT_PORT. */
 
