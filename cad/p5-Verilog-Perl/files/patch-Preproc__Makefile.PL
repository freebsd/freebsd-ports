--- Preproc/Makefile.PL.orig	2016-02-02 23:36:13 UTC
+++ Preproc/Makefile.PL
@@ -9,13 +9,14 @@ use Config;
 
 sub MY::postamble {
     my $out;
+    $CXX = $ENV{CXX};
     #print Config::myconfig();
     if ($Config{osname} !~ /cygwin/i && $Config{archname} !~ /cygwin/i
 	&& $Config{osname} !~ /darwin/i && $Config{archname} !~ /darwin/i) {
 	# Cygwin: Don't change LD, it breaks
 	# Sun: Requires g++ LD
 	# Linux: Either way
-	$out .= "LD = g++\n";
+	$out .= "LD = $CXX\n";
     }
     # Note OPTIMIZE is passed from upper makefile, so this code needed there too.
     my $optimize = $Config{optimize};  $optimize =~ s/(^| )-O2( |$)/\1-O\2/g;
@@ -50,7 +51,7 @@ sub MY::postamble {
     $out .= "${cmt}CFLAGS += -DFLEX_DEBUG\n";
     $out .= "${cmt}LEXFLAGS += -d\n";
     $out .= '
-CC = $(OBJCACHE) g++
+CC = $(OBJCACHE) $(CXX)
 LEX = flex
 YACC = bison
 PPSRC = ../Preproc
