--- lib/Lingua/JA/Romanize/DictJA.pm.orig	2008-01-20 09:56:38 UTC
+++ lib/Lingua/JA/Romanize/DictJA.pm
@@ -58,10 +58,11 @@ $VERSION = "0.23";
 use Lingua::JA::Romanize::Kana;
 use ExtUtils::MakeMaker;
 use Fcntl;
+use File::Temp;
 use IO::File;
 
 my $PERL581 = 1 if ( $] >= 5.008001 );
-my $FETCH_CACHE = "skk";
+my $FETCH_CACHE = File::Temp->newdir;
 my $DICT_DB     = 'Japanese.bdb';
 my $DIC_SMALL   = [ qw(
     skk/SKK-JISYO.S
@@ -130,7 +131,7 @@ sub update {
     my $cand = defined $IO::Zlib::VERSION ? $DIC_GZIPED : $DIC_LARGE;
     print "\t", $_, "\n" foreach (@$cand);
     my $mess = 'Do you wish to download these files?';
-    my $yes = ExtUtils::MakeMaker::prompt( $mess, 'y' );
+    my $yes = ExtUtils::MakeMaker::prompt( $mess, $ENV{DISABLE_DIC_DOWNLOAD} ? 'n' : 'y' );
     if ( $yes eq 'y' ) {
         $diclist = $cand;
     }
