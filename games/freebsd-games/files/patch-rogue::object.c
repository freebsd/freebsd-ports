$FreeBSD$

--- rogue/object.c	30 Nov 1999 03:49:25 -0000	1.5
+++ rogue/object.c	21 Aug 2003 20:04:13 -0000
@@ -159,7 +159,6 @@
 
 extern short cur_level, max_level;
 extern short party_room;
-extern char *error_file;
 extern boolean is_wood[];
 
 put_objects()
