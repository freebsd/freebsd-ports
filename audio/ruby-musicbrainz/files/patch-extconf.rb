--- extconf.rb.orig     Tue Apr 15 14:13:01 2003
+++ extconf.rb  Tue Apr 15 14:13:05 2003
@@ -1,8 +1,9 @@
 require 'mkmf'
 
-$LD_FLAGS = "-lstdc++ -lm"
+$LDFLAGS="-L${PREFIX}/lib -lstdc++ -lm" 
 
 have_library('m', 'pow') and
-have_library('stdc++', '__cxa_rethrow') and
-have_library('musicbrainz', 'mb_Query') and
+have_library('stdc++') and 
+
+have_library('musicbrainz') and
 create_makefile('musicbrainz')
