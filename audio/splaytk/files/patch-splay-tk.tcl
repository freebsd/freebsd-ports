--- splay-tk.tcl.orig	1997-04-06 12:36:35 UTC
+++ splay-tk.tcl
@@ -1,3 +1,9 @@
+#!/bin/sh
+# start up wish \
+exec wish "$0" "$@"
+
+set libdir %%DATADIR%%
+set images ${libdir}
 #####################################################################
 # SPlaY-Tk v2.0p1, (C) Andrew Hobgood                               #
 #                                                                   #
