--- contrib/ircd-shortcut.pl.orig	Fri Jan 11 20:28:57 2008
+++ contrib/ircd-shortcut.pl	Sun Jan 13 14:55:34 2008
@@ -36,7 +36,7 @@
 ######################################
 
 
-open(FILE, '>', 'm_rsshortcut.c');
+open(FILE, '>', '%%WRKSRC%%/contrib/m_rsshortcut.c');
 
 print FILE <<".EOF.";
 /* m_rsshortcut.c
