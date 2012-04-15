--- ./contrib/ircd-shortcut.pl.orig	2008-04-24 16:43:42.000000000 +0100
+++ ./contrib/ircd-shortcut.pl	2008-11-15 02:55:35.000000000 +0000
@@ -36,7 +36,7 @@
 ######################################
 
 
-open(FILE, '>', 'm_rsshortcut.c');
+open(FILE, '>', '%%WRKSRC%%/contrib/m_rsshortcut.c');
 
 print FILE <<".EOF.";
 /* m_rsshortcut.c
