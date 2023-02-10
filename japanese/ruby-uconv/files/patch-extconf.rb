--- extconf.rb.orig	2003-03-12 05:20:47 UTC
+++ extconf.rb
@@ -1,6 +1,6 @@
 require 'mkmf'
 
-$CFLAGS = ""
+$CFLAGS = "-fdeclspec"
 #$CFLAGS="-DUSE_EUC -DUSE_SJIS"
 ##$CFLAGS="-DUSE_SJIS -DUSE_WIN32API"
 
