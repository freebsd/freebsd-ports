--- src/mkinclud.cc.orig	Mon Apr  9 19:43:04 2001
+++ src/mkinclud.cc	Sat Dec 25 12:25:56 2004
@@ -25,7 +25,7 @@
 # compilation setup
 
 # Collection of compilation parameters:
-CFLAGS	= $(SYSFLAGS) $(OPT) $(DEBUG)
+CFLAGS+= $(SYSFLAGS) $(DEBUG)
 
 
 #############################################################################
