--- ./src/Mixfix/modules.yy.orig	2014-09-03 02:57:44.000000000 +0200
+++ ./src/Mixfix/modules.yy	2014-09-03 02:58:03.000000000 +0200
@@ -247,7 +247,7 @@
 			  //	press on.
 			  //
 			  opDescription = lexerBubble;
-			  lexBubble(END_STATEMENT, 1)
+			  lexBubble(END_STATEMENT, 1);
 			}
 			endBubble
 			{
