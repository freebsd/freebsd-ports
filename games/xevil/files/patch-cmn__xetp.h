--- cmn/xetp.h.orig	2012-05-27 06:52:31.000000000 +0900
+++ cmn/xetp.h	2012-05-27 06:53:11.000000000 +0900
@@ -83,9 +83,9 @@
   static void send_rooms_known(OutStreamP,const Rooms &,
                                int worldVersion,Boolean *map);
 
-  static void send_message(OutStreamP,char *msg);
+  static void send_message(OutStreamP,const char *msg);
 
-  static void send_arena_message(OutStreamP,int timeMS,char *msg);
+  static void send_arena_message(OutStreamP,int timeMS,const char *msg);
 
   static void send_command(OutStreamP,const IntelId &,ITcommand);
 
