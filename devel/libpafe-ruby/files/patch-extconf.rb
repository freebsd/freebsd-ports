--- extconf.rb.orig	2011-08-12 11:59:29 UTC
+++ extconf.rb
@@ -1,7 +1,7 @@
 # $Id: extconf.rb,v 1.3 2008-01-15 12:23:29 hito Exp $
 require 'mkmf'
 
-$CFLAGS = "-Wall -O2"
+$CFLAGS = "-Wall -O2 -fdeclspec"
 
 have_header("libpafe/libpafe.h")
 have_library("pafe", "pasori_open")
