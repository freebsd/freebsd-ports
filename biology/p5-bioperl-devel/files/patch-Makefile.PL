--- Makefile.PL.orig	Sun Oct  9 17:16:18 2005
+++ Makefile.PL	Wed Nov 30 13:58:20 2005
@@ -41,7 +41,7 @@
 	     'XML::SAX'                 => '0.0/New style SAX parser/Parsers/Bio::SeqIO::tigrxml,Bio::SeqIO::bsml_sax',
 	     'XML::SAX::Base'                 => '0.0/New style SAX parser/Parsers/Bio::SeqIO::tigrxml,Bio::SeqIO::bsml_sax',
 	     'XML::SAX::Writer'         => '0.0/New style SAX parser/Writers/Bio::SeqIO::tigrxml,Bio::SeqIO::bsml_sax',
- 	     'Bio::ANS1::EntrezGene'    => '0.0/Enztrez Gene Bioperl Parser/Parsers/Bio::SeqIO::entrezgene'
+ 	     'Bio::ASN1::EntrezGene'    => '0.0/Enztrez Gene Bioperl Parser/Parsers/Bio::SeqIO::entrezgene'
 # Bio::Microarray is not in core bioperl yet
 #	     'enum'                     => '0.0/C style enumerated types and bitmask flags 
 # in Perl/Bio::Microarray::Affymetrix::*',
@@ -95,7 +95,7 @@
 sub prompt_for_biodbgff {
   if(  eval { require DBI } && grep {/mysql/} DBI->available_drivers) {
     print "\n** Bio::DB::GFF Tests section** \n";
-    my $proceed = prompt("Do you want to run the BioDBGFF tests (requires a mysql, postgres or oracle database) y/n",'n');
+    my $proceed = 'n'; # prompt("Do you want to run the BioDBGFF tests (requires a mysql, postgres or oracle database) y/n",'n');
     if( $proceed =~ /^[yY]/) {
       my $cfg = {dbd_driver => 'mysql'};
       GFFQueryDb($cfg,{'prompt'=>1,'verbose'=>1});
@@ -129,7 +129,7 @@
 sub get_scripts_to_install {
   print "\n*** Script Install Section ****\n";
   print "\nBioperl comes with a number of useful scripts which you may wish to install.\n";
-  my $prompt_mode = prompt("Install [a]ll Bioperl scripts, [n]one, or choose groups [i]nteractively?",'a');
+  my $prompt_mode = 'a'; # prompt("Install [a]ll Bioperl scripts, [n]one, or choose groups [i]nteractively?",'a');
   return if $prompt_mode =~ /^[nN]/;
   my @scripts;
   my $script_dir = './scripts';
@@ -378,16 +378,16 @@
 );
 
 
-sub MY::manifypods {
-  my $self = shift;
-  #print STDERR "In manifypods moment\n";
-  if( 1 ) {
-    return "\nmanifypods : pure_all\n\t$self->{NOECHO}\$(NOOP)\n"
-  }
-  else {
-    return $self->SUPER::manifypods(@_);
-  }
-}
+#sub MY::manifypods {
+#  my $self = shift;
+#  #print STDERR "In manifypods moment\n";
+#  if( 1 ) {
+#    return "\nmanifypods : pure_all\n\t$self->{NOECHO}\$(NOOP)\n"
+#  }
+#  else {
+#    return $self->SUPER::manifypods(@_);
+#  }
+#}
 
 sub MY::clean {
   package MY;
