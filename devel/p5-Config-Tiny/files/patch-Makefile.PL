--- Makefile.PL.orig	Wed Apr 16 18:04:51 2003
+++ Makefile.PL	Mon Dec  8 19:41:19 2003
@@ -8,6 +8,9 @@
 		FindBin    => 0,
 
 	},
+	'MAN3PODS'	=> {
+		'lib/Config/Tiny.pm' => '$(INST_MAN3DIR)/Config::Tiny.3'
+	},
 	($] >= 5.005) ? (
 		'AUTHOR'   => 'Adam Kennedy (cpan@ali.as)',
 		'ABSTRACT' => 'Read/Write .ini style files with as little code as possible',
