--- Makefile.PL.orig	2011-10-26 14:33:18.000000000 +0800
+++ Makefile.PL	2011-11-20 17:28:21.555225857 +0800
@@ -146,11 +146,9 @@
     clean   => {
         FILES   => "@do_clean",
     },
-    'MYEXTLIB'     => $MING_TOP_BUILDDIR . '/src/.libs/libming.a',
     'OBJECT'       => "$XS_OBJECTS",
     'LDFROM'       => "$LD_OBJECTS",
     'INC'          => "-I$MING_TOP_SRCDIR/src -I$BUILDDIR -I$MING_TOP_BUILDDIR/src -I$SRCDIR",
-    'LIBS'         => [ $libs ],
     'PM'	   => $PM_HASH,
     'MAN3PODS'	   => $MAN3_HASH,
     'TYPEMAPS'     => ["$SRCDIR/typemap"],
@@ -164,17 +162,7 @@
 
 sub ming_is_compiled
 {
-	my $libming = $MING_TOP_BUILDDIR."/src/.libs/libming.a";
-
-	if ( -e $libming )
-	{
-		return 1;
-	}
-	else
-	{
-    		print "$libming doesn't exist.\n";
-		return undef;
-	}
+	return 1;
 }
 
 # unused. At least it should take into account the configure flags by
