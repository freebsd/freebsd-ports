--- src/CKeyboard.h.orig	2005-04-25 18:25:38.000000000 +0000
+++ src/CKeyboard.h	2007-10-31 02:29:26.000000000 +0000
@@ -8,6 +8,6 @@
 	
 		Keyboard();
 		void setDefaultKeys();
-		static char *Keyboard::translateKey(int value);
+		static char *translateKey(int value);
 
 };
