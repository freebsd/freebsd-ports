--- perl_ext/Makefile.PL.orig	2011-08-07 14:41:33.558563705 -0400
+++ perl_ext/Makefile.PL	2011-08-07 14:44:13.341563378 -0400
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
