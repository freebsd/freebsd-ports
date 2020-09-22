--- src/spacecomm.c.orig	2013-12-18 18:53:03 UTC
+++ src/spacecomm.c
@@ -63,7 +63,7 @@ SENDOBJUNMOD0
 #define SENDORDERS 1
 
 extern struct HeadObjList listheadobjs;
-struct TextMessageList listheadtext;
+extern struct TextMessageList listheadtext;
 extern struct CharListHead gameloglist;          /* list of all game messages */
 extern struct Window windowgamelog;
 extern struct Habitat habitat;
