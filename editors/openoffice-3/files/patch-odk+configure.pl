o gmake support
o suggestion from Juegen Schmidt <Juergen.Schmidt@Sun.COM>

http://www.openoffice.org/issues/show_bug.cgi?id=41142

Index: odk/configure.pl
===================================================================
RCS file: /cvs/api/odk/configure.pl,v
retrieving revision 1.8.4.10
diff -u -r1.8.4.10 configure.pl
--- odk/configure.pl	11 Jan 2005 11:00:15 -0000	1.8.4.10
+++ odk/configure.pl	23 Jan 2005 09:13:41 -0000
@@ -43,7 +43,14 @@
 }
 
 $main::OO_SDK_MAKE_HOME = "";
+$main::OO_MAKE_NAME = "make";
+if ( $main::operatingSystem eq "FreeBSD" )
+{
+    $main::OO_MAKE_NAME = "gmake";
+    $main::OO_SDK_MAKE_HOME_SUGGESTION = searchprog("gmake");
+} else {
 $main::OO_SDK_MAKE_HOME_SUGGESTION = searchprog("make");
+}
 $main::makeVersion = "3.79.1";
 $main::correctVersion = 0;
 
@@ -137,7 +144,7 @@
 # prepare GNU make path
 while ( (!$main::correctVersion) &&
 		((! -d "$main::OO_SDK_MAKE_HOME" ) ||
-		 ((-d "$main::OO_SDK_MAKE_HOME") && (! -e "$main::OO_SDK_MAKE_HOME/make"))) )
+		 ((-d "$main::OO_SDK_MAKE_HOME") && (! -e "$main::OO_SDK_MAKE_HOME/$main::OO_MAKE_NAME" ))) )
 {
     print " Enter GNU make ($main::makeVersion or higher) tools directory [$main::OO_SDK_MAKE_HOME_SUGGESTION]: ";
     $main::OO_SDK_MAKE_HOME = readStdIn();
@@ -146,15 +153,16 @@
     {
 		$main::OO_SDK_MAKE_HOME = $main::OO_SDK_MAKE_HOME_SUGGESTION;
     }
+
     if ( (! -d "$main::OO_SDK_MAKE_HOME") || 
-		 ((-d "$main::OO_SDK_MAKE_HOME") && (! -e "$main::OO_SDK_MAKE_HOME/make")) )
+		 ((-d "$main::OO_SDK_MAKE_HOME") && (! -e "$main::OO_SDK_MAKE_HOME/$main::OO_MAKE_NAME")) )
     { 
 		$main::OO_SDK_MAKE_HOME = "";
 		print " Error: GNU make is required, please specify a GNU make tools directory.\n";
     } else 
     {
 		#check version
-		my $testVersion = `$OO_SDK_MAKE_HOME/make --version`;
+		my $testVersion = `$OO_SDK_MAKE_HOME/$main::OO_MAKE_NAME --version`;
 		if ( $testVersion eq "")
 		{
 			print " Set the environment variable OO_SDK_MAKE_HOME to your GNU build tools directory.\n";
@@ -165,7 +173,7 @@
 			{
 				$testVersion = $1;
 			}
-			$main::correctVersion = testVersion($main::makeVersion, $testVersion, "$main::OO_SDK_MAKE_HOME/make", 1);
+			$main::correctVersion = testVersion($main::makeVersion, $testVersion, "$main::OO_SDK_MAKE_HOME/$main::OO_MAKE_NAME", 1);
 			if ( !$main::correctVersion )
 			{
 				print " The 'make' command found at '$main::OO_SDK_MAKE_HOME' has a wrong version\n";
