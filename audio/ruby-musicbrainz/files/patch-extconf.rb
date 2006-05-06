--- extconf.rb.orig	Thu May  4 19:53:01 2006
+++ extconf.rb	Thu May  4 19:54:13 2006
@@ -1,9 +1,9 @@
 require 'mkmf'
 
-$LD_FLAGS = "-lstdc++ -lm"
+$LDFLAGS="-L${PREFIX}/lib -lstdc++ -lm"
 
 have_func('pow', 'math.h') and
 # note, this causes problems in cygwin.  any suggestions?
-have_library('stdc++', '__cxa_rethrow') and
-have_library('musicbrainz', 'mb_Query') and
+have_library('stdc++') and 
+have_library('musicbrainz') and
 create_makefile('musicbrainz')
