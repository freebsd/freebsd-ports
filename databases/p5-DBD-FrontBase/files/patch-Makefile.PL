--- ../DBD-FB-1.37.orig/Makefile.PL	Wed Nov  1 19:44:28 2006
+++ Makefile.PL	Fri Jul 20 14:31:09 2007
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
+# The FreeBSD port of FrontBase puts the libs in an unexpected location.
+# The test for the FrontBase lib dir has been removed.
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
