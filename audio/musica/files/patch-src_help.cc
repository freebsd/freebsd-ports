--- src/help.cc.orig	2007-12-18 19:46:20.000000000 +0100
+++ src/help.cc	2007-12-18 19:46:34.000000000 +0100
@@ -59,7 +59,7 @@
 
 
 
-static char *copyingText = 
+static char copyingText[] = 
 PACKAGE " " VERSION "  -  a MIDI player\n\n" \
 "Copyright (C) 1999, Erik Mouw (J.A.K.Mouw@its.tudelft.nl)\n\n" \
 "This program is free software; you can redistribute it and/or modify " \
