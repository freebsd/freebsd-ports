deh_edge/english.h:35:63: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
#define LOADNET   "you can't do load while in a net game!\n\n"PRESSKEY
                                                              ^

--- deh_edge/english.h.orig	2018-07-28 06:12:45 UTC
+++ deh_edge/english.h
@@ -32,29 +32,29 @@ namespace Deh_Edge
 #define PRESSKEY   "press a key."
 #define PRESSYN   "press y or n."
 #define QUITMSG  "are you sure you want to\nquit this great game?"
-#define LOADNET   "you can't do load while in a net game!\n\n"PRESSKEY
-#define QLOADNET  "you can't quickload during a netgame!\n\n"PRESSKEY
-#define QSAVESPOT  "you haven't picked a quicksave slot yet!\n\n"PRESSKEY
-#define SAVEDEAD   "you can't save if you aren't playing!\n\n"PRESSKEY
-#define QSPROMPT   "quicksave over your game named\n\n'%s'?\n\n"PRESSYN
-#define QLPROMPT  "do you want to quickload the game named\n\n'%s'?\n\n"PRESSYN
+#define LOADNET   "you can't do load while in a net game!\n\n" PRESSKEY
+#define QLOADNET  "you can't quickload during a netgame!\n\n" PRESSKEY
+#define QSAVESPOT  "you haven't picked a quicksave slot yet!\n\n" PRESSKEY
+#define SAVEDEAD   "you can't save if you aren't playing!\n\n" PRESSKEY
+#define QSPROMPT   "quicksave over your game named\n\n'%s'?\n\n" PRESSYN
+#define QLPROMPT  "do you want to quickload the game named\n\n'%s'?\n\n" PRESSYN
 
 #define NEWGAME  \
 "you can't start a new game\n"\
-"while in a network game.\n\n"PRESSKEY
+"while in a network game.\n\n" PRESSKEY
 
 #define NIGHTMARE  \
 "are you sure? this skill level\n"\
-"isn't even remotely fair.\n\n"PRESSYN
+"isn't even remotely fair.\n\n" PRESSYN
 
 #define SWSTRING  \
 "this is the shareware version of doom.\n\n"\
-"you need to order the entire trilogy.\n\n"PRESSKEY
+"you need to order the entire trilogy.\n\n" PRESSKEY
 
 #define MSGOFF  "Messages OFF"
 #define MSGON    "Messages ON"
-#define NETEND  "you can't end a netgame!\n\n"PRESSKEY
-#define ENDGAME  "are you sure you want to end the game?\n\n"PRESSYN
+#define NETEND  "you can't end a netgame!\n\n" PRESSKEY
+#define ENDGAME  "are you sure you want to end the game?\n\n" PRESSYN
 
 #define DOSY    "(press y to quit)"
 
@@ -726,11 +726,11 @@ namespace Deh_Edge
 #define DETAILLO      "Low detail"
 
 #define QUITMSG       "are you sure you want to\nquit this great game?"
-#define QLOADNET      "you can't quickload during a netgame!\n\n"PRESSKEY
+#define QLOADNET      "you can't quickload during a netgame!\n\n" PRESSKEY
 
 #define SWSTRING      \
 "this is the shareware version of doom.\n\n"\
-"you need to order the entire trilogy.\n\n"PRESSKEY
+"you need to order the entire trilogy.\n\n" PRESSKEY
 
 }  // Deh_Edge
 
