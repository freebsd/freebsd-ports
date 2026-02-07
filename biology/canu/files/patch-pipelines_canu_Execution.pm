--- pipelines/canu/Execution.pm.orig	2020-09-07 19:08:24 UTC
+++ pipelines/canu/Execution.pm
@@ -762,8 +762,8 @@ sub submitScript ($$) {
 
 
 
-sub buildGridArray ($$$$) {
-    my ($name, $bgn, $end, $opt) = @_;
+sub buildGridArray (@) {
+    my ( $name, $bgn, $end, $opt, $thr ) = @_;
     my  $off = 0;
 
     #  In some grids (SGE)   this is the maximum size of an array job.
@@ -803,9 +803,43 @@ sub buildGridArray ($$$$) {
         $off = "-F \"$off\"";
     }
 
-    $opt =~ s/ARRAY_NAME/$name/g;        #  Replace ARRAY_NAME with 'job name'
-    $opt =~ s/ARRAY_JOBS/$bgn-$end/g;    #  Replace ARRAY_JOBS with 'bgn-end'
+    if( $opt =~ m/(ARRAY_NAME)/ )
+    {
+	$opt =~ s/$1/$name/; # Replace ARRAY_NAME with 'job name'
+    }
+    elsif( $opt =~ m/(ARRAY_JOBS)/ )
+    {
+	$opt =~ s/$1/$bgn-$end/; # Replace ARRAY_JOBS with 'bgn-end'
 
+	if( lc( getGlobal( 'gridEngine' ) ) eq 'slurm' && $end > 1 )
+	{
+	    if( $name =~ m/^cormhap_/i && defined getGlobal( 'slurmCormhapCoreLimit' ) )
+	    {
+		$opt .= '%' . int( getGlobal( 'slurmCormhapCoreLimit' ) / $thr );
+	    }
+	    elsif( $name =~ m/^ovb_/i && defined getGlobal( 'slurmOvbCoreLimit' ) )
+	    {
+		$opt .= '%' . getGlobal( 'slurmOvbCoreLimit' );
+	    }
+	    elsif( $name =~ m/^ovs_/i && defined getGlobal( 'slurmOvsCoreLimit' ) )
+	    {
+		$opt .= '%' . getGlobal( 'slurmOvsCoreLimit' );
+	    }
+	    elsif( $name =~ m/^red_/i && defined getGlobal( 'slurmRedCoreLimit' ) )
+	    {
+		$opt .= '%' . int( getGlobal( 'slurmRedCoreLimit' ) / $thr );
+	    }
+	    elsif( defined getGlobal( 'slurmArrayTaskLimit' ) )
+	    {
+		$opt .= '%' . getGlobal( 'slurmArrayTaskLimit' );
+	    }
+	    elsif( defined getGlobal( 'slurmArrayCoreLimit' ) )
+	    {
+		$opt .= '%' . int( getGlobal( 'slurmArrayCoreLimit' ) / $thr );
+	    }
+	}
+    }
+
     return($opt, $off);
 }
 
@@ -951,7 +985,7 @@ sub buildGridJob ($$$$$$$$$) {
     my $jobNameT               = makeUniqueJobName($jobType, $asm);
 
     my ($jobName,  $jobOff)    = buildGridArray($jobNameT, $bgnJob, $endJob, getGlobal("gridEngineArrayName"));
-    my ($arrayOpt, $arrayOff)  = buildGridArray($jobNameT, $bgnJob, $endJob, getGlobal("gridEngineArrayOption"));
+    my ( $arrayOpt, $arrayOff ) = buildGridArray( $jobNameT, $bgnJob, $endJob, getGlobal( "gridEngineArrayOption" ), $thr );
 
     my $outputOption           = buildOutputOption($path, $script);
 
