--- contrib/VelvetOptimiser/VelvetOptimiser.pl.orig	2009-09-14 23:44:19.000000000 +0900
+++ contrib/VelvetOptimiser/VelvetOptimiser.pl	2009-10-30 22:13:45.000000000 +0900
@@ -44,9 +44,10 @@
 my @hashvals;
 my %assemblies;
 my $readfile;
+my $MAXKMERLENGTH = %%MAXKMERLENGTH%%;
 my $logfile = "logfile.txt";
 my $hashs = 19;
-my $hashe = 129;
+my $hashe = $MAXKMERLENGTH;
 my $ass_num = 1;
 my $interested = 1;
 
@@ -311,26 +312,26 @@
     my $ass = shift;
     print STDERR "\tPlease type in the insert length for the short reads: ";
     #my $len = <>;
-    my $len = "200"; #do not ask for insert size!
+    my $len = "auto"; #do not ask for insert size!
     chomp($len);
-    while($len =~ /\D+/){
-        print STDERR "\tThe length needs to be a number, please re-enter: ";
-        $len = <>;
-        chomp($len);
-    }
+    #while($len =~ /\D+/){
+    #    print STDERR "\tThe length needs to be a number, please re-enter: ";
+    #    $len = <>;
+    #    chomp($len);
+    #}
     print STDERR strftime("%b %e %H:%M:%S", localtime), " Running assembly with short insert length $len\n";
     print OUT strftime("%b %e %H:%M:%S", localtime), " Running assembly with short insert length $len\n";
 
     #re-write the pstringg with the new velvetg command..
-    my $vg = $ass->{pstringg};
-    if($vg =~ /ins_length /){
-        $vg =~ s/ins_length\s+\d+/ins_length $len/;
-    }
-    else {
-        $vg .= " -ins_length $len";
-    }
+    #my $vg = $ass->{pstringg};
+    #if($vg =~ /ins_length /){
+    #    $vg =~ s/ins_length\s+\d+/ins_length $len/;
+    #}
+    #else {
+    #    $vg .= " -ins_length $len";
+    #}
 
-    $ass->{pstringg} = $vg;
+    #$ass->{pstringg} = $vg;
     my $worked = VelvetOpt::gwrap::objectVelvetg($ass);
     if($worked){
         $ass->getAssemblyDetails();
@@ -347,8 +348,8 @@
 my $usage = "\nVelvetOptimiser.pl: A script to run the Velvet assembler and optimise its output. Simon Gladman - CSIRO 2008, 2009.\n\n";
 $usage .= "Usage: VelvetOptimiser.pl <-f 'velveth parameters'> [-s <hash start>] [-e <hash end>] [-a <yes>]\n\n";
 $usage .= "Where:\t<-f 'velveth parameters'> is the parameter line normally passed to velveth in quotes.\n";
-$usage .= "\t-s <hash start> The hash value you want velvet to start looking from. Default: 19. MUST BE ODD > 0 & <=31!\n";
-$usage .= "\t-e <hash end> The hash value you want velvet to stop looking at. Default: 31. MUST BE ODD AND > START & <= 31!\n";
+$usage .= "\t-s <hash start> The hash value you want velvet to start looking from. Default: 19. MUST BE ODD > 0 & <=$MAXKMERLENGTH!\n";
+$usage .= "\t-e <hash end> The hash value you want velvet to stop looking at. Default: $MAXKMERLENGTH. MUST BE ODD AND > START & <= $MAXKMERLENGTH!\n";
 $usage .= "\t-a <yes> The final optimised assembly will include read tracking and amos file outputs (however, intermediate assemblies won't.)\n";
 $usage .= "\nIf the optimizer requires an insert length for some paired end data, it will ask for it when it gets to the optimization step.\n";
 
@@ -390,9 +391,9 @@
     $hashs = $opts{'s'};
        print STDERR "\n\t\t's-Param' is >$hashs<\n";
     unless($hashs =~ /^\d+$/){ die "\tFatal error! Start hash not a number!\n$usage";}
-    if($hashs > 129){
-        print STDERR "\tStart hash value too high.  New start hash value is 129.\n";
-        $hashs = 129;
+    if($hashs > $MAXKMERLENGTH){
+        print STDERR "\tStart hash value too high.  New start hash value is $MAXKMERLENGTH.\n";
+        $hashs = $MAXKMERLENGTH;
     }
     if(!&isOdd($hashs)){
         $hashs = $hashs - 1;
@@ -404,9 +405,9 @@
 if($opts{'e'}){
     $hashe = $opts{'e'};
     unless($hashe =~ /^\d+$/){ die "\tFatal error! End hash not a number!\n$usage";}
-    if($hashe > 129 || $hashe < 1){
-        print STDERR "\tEnd hash value not in workable range.  New end hash value is 129.\n";
-        $hashe = 129;
+    if($hashe > $MAXKMERLENGTH || $hashe < 1){
+        print STDERR "\tEnd hash value not in workable range.  New end hash value is $MAXKMERLENGTH.\n";
+        $hashe = $MAXKMERLENGTH;
     }
     if($hashe < $hashs){
         print STDERR "\tEnd hash value lower than start hash value.  New end hash value = $hashs.\n";
