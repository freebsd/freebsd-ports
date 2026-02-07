--- tbl2mim.awk.orig	2006-12-08 03:01:57.000000000 +0100
+++ tbl2mim.awk	2008-03-30 19:20:34.000000000 +0200
@@ -1,4 +1,4 @@
-#!/usr/bin/gawk
+#!/usr/bin/awk
 # Copyright (C) 2006
 #   National Institute of Advanced Industrial Science and Technology (AIST)
 #   Registration Number H15PRO112
@@ -25,6 +25,7 @@
     begin_table = 0;
 }
 
+/^ *###/ { next; }
 /^ICON *=/ { ICON = " \""$3"\""; next; }
 /^NAME *=/ { NAME = tolower($3); next; }
 /^LANGUAGES *=/ { LANG = $3; next; }
