--- Makefile.PL.orig	2008-05-26 16:19:52.000000000 +1000
+++ Makefile.PL	2008-05-26 16:20:12.000000000 +1000
@@ -13,37 +13,10 @@
 
 my $os = $^O;
 
-if (! $ENV{FRONTBASE_HOME}) {
-    print "Environment variable FRONTBASE_HOME not defined. Searching for Frontbase...\n";
-	if ($os eq 'MSWin32')
-	{ 
-		foreach(qw(\usr\FrontBase)) 
-		{
-			if (-d "$_/lib") 
-			{
-				$ENV{FRONTBASE_HOME} = $_;
-				last;
-			}
-		}
-	}
-	else
-	{
-		foreach(qw(/Library/Frontbase /Local/Library/FrontBase /usr/FrontBase /opt/FrontBase /usr/local/FrontBase)) 
-		{
-			if (-d "$_/lib") 
-			{
-				$ENV{FRONTBASE_HOME} = $_;
-				last;
-			}
-		}
-	}
-}
-
-if (defined($ENV{FRONTBASE_HOME}) && -d "$ENV{FRONTBASE_HOME}/lib") {
-    print "Found Frontbase in $ENV{FRONTBASE_HOME}\n";
-} else {
-    die "Unable to find Frontbase\nplease set environment variable FRONTBASE_HOME\n";
-}
+#
+# The FreeBSD port for FrontBase puts the libraries in an unexpected location and causes the Makefile to die.  As we know
+# that the package is installed at this point, the test for the libraries has been removed.
+#
 
 print "Configuring for ",$os, "\n";
 
@@ -59,7 +32,7 @@
     DISTNAME		=> 'DBD-FB',
     VERSION_FROM	=> 'FB.pm',
     INC				=> "-I$ENV{FRONTBASE_HOME}/include -I\$(INSTALLSITEARCH)/auto/DBI -I\$(INSTALLARCHLIB)/DBI -I\$(SITEARCH)/auto/DBI -I\$(ARCHLIB)/DBI",
-	OBJECT			=> "FB\$(OBJ_EXT) dbdimp\$(OBJ_EXT) $ENV{FRONTBASE_HOME}/lib/$libFBCAccess",
+	OBJECT			=> "FB\$(OBJ_EXT) dbdimp\$(OBJ_EXT) /usr/local/lib/$libFBCAccess",
 	dist			=> { COMPRESS => 'gzip -9f', SUFFIX => 'gz', POSTOP => 'mv $(DISTNAME)-$(VERSION).tar.gz ../' },
 	realclean		=> { FILES => '*.xsi' }
 );
