--- config/milestone.pl.orig	2013-02-11 22:33:22 UTC
+++ config/milestone.pl
@@ -55,7 +55,7 @@ $MILESTONE_FILE  = "$TOPSRCDIR/config/mi
 #
 my $milestone = Moz::Milestone::getOfficialMilestone($MILESTONE_FILE);
 
-if (defined(@TEMPLATE_FILE)) {
+if (@TEMPLATE_FILE) {
   my $TFILE;
 
   foreach $TFILE (@TEMPLATE_FILE) {
