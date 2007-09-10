--- admin/detect-autoconf.pl.orig	2007-05-14 03:57:35.000000000 -0700
+++ admin/detect-autoconf.pl	2007-09-10 02:02:32.000000000 -0700
@@ -5,2 +5,5 @@
 #
+# Stripped down for new FreeBSD autotools environment
+# Ade Lovett <ade@FreeBSD.org> 2007-09-10
+#
 # Copyright (c) 2005.
@@ -23,69 +26,2 @@
 
-# Subroutine to determine the highest installed version of the given program,
-# searching from the given paths.
-sub findBest
-{
-    my ($program, @paths) = @_;
-    my $best_version_found = '0'; # Deliberately a string.
-    my %versions;
-    my %minimumVersions = (
- 	'autoconf' => '2.5',
-	'automake' => '1.6',
-    );
-
-    # Allow user to use environment variable to override search.
-    return $ENV{uc $program} if $ENV{uc $program};
-
-    for $prefix (@paths)
-    {
-	@files = glob "$prefix/$program*";
-	for $file (@files)
-	{
-	    # Don't check non-executable scripts.
-	    next unless -x $file;
-
-	    ($version) = $file =~ /$prefix\/$program-?(.*)$/;
-	    $version =~ s/-|\.//g;
-
-	    # Special case some programs to make sure it has a minimum version.
-	    if (not $version and exists $minimumVersions{$program})
-	    {
-		my $min_version = $minimumVersions{$program};
-		my $versionOutput = `$program --version 2>/dev/null | head -n 1`;
-
-		# If we can't run the script to get the version it likely won't work later.
-		next unless $versionOutput; 
-
-		# Use number.number for version (we don't need the excess in general).
-		($versionOutput) = ($versionOutput =~ /(\d\.\d)/);
-
-		# Use lt to do lexicographical comparison of strings (which should be
-		# equivalent and doesn't involve issues with floating point conversions).
-		if (not $versionOutput or $versionOutput lt $min_version)
-		{
-		    next;
-		}
-	    }
-
-	    # If no version suffix then use it in favor of a versioned autotool
-	    # since the ever-popular WANT_AUTOFOO should then work (in theory).
-	    return $file unless $version;
-
-	    # Emulate 'which', and abort if we've already seen this version.
-	    next if exists $versions{$version};
-
-	    # Save filename of program.
-	    $versions{$version} = $file;
-
-	    # Use string comparison so that e.g. 253a will be > 253 but < 254.
-	    if ($version gt $best_version_found)
-	    {
-		$best_version_found = $version;
-	    }
-	}
-    }
-
-    return $versions{$best_version_found};
-}
-
 # Find an appropriate "which" program for later use by the shell script calling
@@ -103,13 +39,2 @@
 
-# Uses which() to find a program unless the user provided its path in the
-# environment (the upper case program name is searched).
-sub findProgram
-{
-    $suffix = ""; # For use if @_ has only one param.
-    my ($program, $suffix) = @_;
-
-    return $ENV{uc $program} if $ENV{uc $program};
-    return which("$program$suffix");
-}
-
 # SCRIPT STARTS.
@@ -123,45 +48,12 @@
 
-$autoconf = findBest('autoconf', @paths);
-($autoconf_suffix) = $autoconf =~ /.*autoconf(.*)$/;
-
-# Find matching autoconf companions.
-$autoheader = findProgram('autoheader', $autoconf_suffix);
-$autom4te = findProgram('autom4te', $autoconf_suffix);
-
-# Get best automake, and look for unsermake to possibly override it.
-$automake = findBest('automake', @paths);
-$unsermake = "";
-# backward compatible: if $UNSERMAKE points to a path, use it
-$unsermake = findProgram('unsermake') if (defined($ENV{'UNSERMAKE'}) and $ENV{'UNSERMAKE'} =~ /\//);
-# new compatible: if it says 'yes', use the one from path
-$unsermake = which('unsermake') if ($ENV{'UNSERMAKE'} ne 'no');
-
-($automake_suffix) = $automake =~ /.*automake(.*)$/;
-
-# Use unsermake if we found it.
-$automake = "$unsermake -c" if $unsermake;
-
-# Find matching automake companions.
-$aclocal = findProgram('aclocal', $automake_suffix);
-
 $which = findWhich();
 
-# Make sure we have all of the needed programs.
-for $i (qw'autoconf autoheader autom4te automake aclocal')
-{
-    unless(${$i})
-    {
-	print "# Unable to find $i!!\n";
-	exit 1;
-    }
-}
-
 # Print results in eval-able form.
 print <<EOF;
-AUTOCONF="$autoconf"
-AUTOHEADER="$autoheader"
-AUTOM4TE="$autom4te"
+AUTOCONF="autoconf"
+AUTOHEADER="autoheader"
+AUTOM4TE="autom4te"
 
-AUTOMAKE="$automake"
-ACLOCAL="$aclocal"
+AUTOMAKE="automake"
+ACLOCAL="aclocal"
 
