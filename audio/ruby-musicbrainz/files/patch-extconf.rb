--- extconf.rb.orig	Sat Aug 21 19:41:02 2004
+++ extconf.rb	Sun Dec 26 05:17:30 2004
@@ -1,8 +1,8 @@
 require 'mkmf'
 
-$LD_FLAGS = "-lstdc++ -lm"
+$LDFLAGS="-L${PREFIX}/lib -lstdc++ -lm" 
 
-have_library('m', 'pow') and
-have_library('stdc++', '__cxa_rethrow') and
-have_library('musicbrainz', 'mb_Query') and
+have_library('m') and
+have_library('stdc++') and 
+have_library('musicbrainz') and
 create_makefile('musicbrainz')
