--- Makefile.PL.orig	Sat Dec 21 15:01:55 2002
+++ Makefile.PL	Mon May 12 18:25:11 2003
@@ -8,6 +8,9 @@
 		FindBin    => 0,
 		
 	},	
+	'MAN3PODS'     => {
+	    'lib/Config/Tiny.pm' => '$(INST_MAN3DIR)/Config::Tiny.3'
+	},
 	($] >= 5.005) ? (
 		'AUTHOR'   => 'Adam Kennedy (adam@ali.as)',
 		'ABSTRACT' => 'Read/Write .ini style files with as little code as possible',
