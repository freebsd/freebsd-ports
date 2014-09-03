--- ./src/Mixfix/commands.yy.orig	2014-09-03 02:51:54.000000000 +0200
+++ ./src/Mixfix/commands.yy	2014-09-03 02:53:05.000000000 +0200
@@ -23,12 +23,12 @@
 /*
  *	Commands.
  */
-command		:	KW_SELECT		{ lexBubble(END_COMMAND, 1) }
+command		:	KW_SELECT		{ lexBubble(END_COMMAND, 1); }
 			endBubble
 			{
 			  interpreter.setCurrentModule(lexerBubble);
 			}
-		|	KW_DUMP			{ lexBubble(END_COMMAND, 1) }
+		|	KW_DUMP			{ lexBubble(END_COMMAND, 1); }
 			endBubble
 			{
 			  if (interpreter.setCurrentModule(lexerBubble))
