--- toon.c.orig	2008-02-25 16:41:19 UTC
+++ toon.c
@@ -95,6 +95,8 @@
 #include <stdio.h>
 #include <string.h>
 
+char toon_message[TOON_MESSAGE_LENGTH];
+
 /* Time to throw up. Here is a kludgey function that recursively calls
  * itself (up to a limit) to find the window ID of the KDE desktop to
  * draw on. It works with KDE 2.0, but since KDE 2.0 is less stable
