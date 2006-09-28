diff -ruN 1035.c.orig 1035.c
--- 1035.c.orig	Tue Feb 18 08:54:33 2003
+++ 1035.c	Mon Sep 25 22:11:14 2006
@@ -1,4 +1,5 @@
 #include "1035.h"
+#include <stdio.h>
 #include <string.h> 
 
 unsigned short int net2short(unsigned char **bufp)
@@ -241,7 +242,7 @@
     if(packet == 0 || m == 0) return;
 
     // keep all our mem in one (aligned) block for easy freeing
-    #define my(x,y) while(m->_len&7) m->_len++; (void*)x = (void*)(m->_packet + m->_len); m->_len += y;
+    #define my(x,y) x = (void *) x; while(m->_len&7) m->_len++; x = (void*)(m->_packet + m->_len); m->_len += y;
 
     // header stuff bit crap
     m->_buf = buf = packet;
