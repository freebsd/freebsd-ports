--- ext/Errno/Errno_pm.PL.orig	2014-10-01 01:33:00 UTC
+++ ext/Errno/Errno_pm.PL
@@ -236,20 +236,31 @@ sub write_errno_pm {
     {	# BeOS (support now removed) did not enter this block
     # invoke CPP and read the output
 
+	my $inhibit_linemarkers = '';
+	if ($Config{gccversion} =~ /\A(\d+)\./ and $1 >= 5) {
+	    # GCC 5.0 interleaves expanded macros with line numbers breaking
+	    # each line into multiple lines. RT#123784
+	    $inhibit_linemarkers = ' -P';
+	}
+
 	if ($^O eq 'VMS') {
-	    my $cpp = "$Config{cppstdin} $Config{cppflags} $Config{cppminus}";
+	    my $cpp = "$Config{cppstdin} $Config{cppflags}" .
+		$inhibit_linemarkers . " $Config{cppminus}";
 	    $cpp =~ s/sys\$input//i;
 	    open(CPPO,"$cpp  errno.c |") or
 		die "Cannot exec $Config{cppstdin}";
 	} elsif ($IsMSWin32 || $^O eq 'NetWare') {
-	    open(CPPO,"$Config{cpprun} $Config{cppflags} errno.c |") or
-		die "Cannot run '$Config{cpprun} $Config{cppflags} errno.c'";
+	    my $cpp = "$Config{cpprun} $Config{cppflags}" .
+		$inhibit_linemarkers;
+	    open(CPPO,"$cpp errno.c |") or
+		die "Cannot run '$cpp errno.c'";
 	} elsif ($IsSymbian) {
-            my $cpp = "gcc -E -I$ENV{SDK}\\epoc32\\include\\libc -";
+            my $cpp = "gcc -E -I$ENV{SDK}\\epoc32\\include\\libc" .
+		$inhibit_linemarkers ." -";
 	    open(CPPO,"$cpp < errno.c |")
 		or die "Cannot exec $cpp";
         } else {
-	    my $cpp = default_cpp();
+	    my $cpp = default_cpp() . $inhibit_linemarkers;
 	    open(CPPO,"$cpp < errno.c |")
 		or die "Cannot exec $cpp";
 	}
