--- Makefile.PL.orig	Tue May  6 14:29:54 2003
+++ Makefile.PL	Tue May  6 14:31:57 2003
@@ -5,6 +5,9 @@
 			  'NAME'	=> 'Apache::DBILogConfig',
 			  'VERSION_FROM' => 'DBILogConfig.pm', # finds $VERSION
+ 			  'MAN3PODS' => {
+			      'DBILogConfig.pm' => '$(INST_MAN3DIR)/Apache::DBILogConfig.$(MAN3EXT)'
+			  },
 			  'dist'    => {
 							COMPRESS=> 'gzip -9f', SUFFIX=>'gz',
 							PREOP => 'pod2text DBILogConfig.pm > README',
