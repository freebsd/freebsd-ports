--- ./contrib/ircd-shortcut.pl.orig	2008-06-29 14:05:58.000000000 +0100
+++ ./contrib/ircd-shortcut.pl	2008-06-29 14:07:11.000000000 +0100
@@ -36,7 +36,7 @@
 ######################################
 
 
-open(FILE, '>', 'm_rsshortcut.c');
+open(FILE, '>', '%%WRKSRC%%/contrib/m_rsshortcut.c');
 
 print FILE <<".EOF.";
 /* m_rsshortcut.c
