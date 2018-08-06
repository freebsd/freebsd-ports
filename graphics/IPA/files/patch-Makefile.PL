Fix regular expression match and build with MakeMaker >= 7.05_05 which adds a
space between the target name and the operator.

--- Makefile.PL.orig	2011-05-14 06:27:26 UTC
+++ Makefile.PL
@@ -79,8 +79,8 @@ H
 sub c_o
 {
 	my $t = shift-> SUPER::c_o(@_);
-	unless ( $t =~ /.c\$\(OBJ_EXT\):\n\t.*\$\*\$\(OBJ_EXT\)/ ) {
-		$t =~ s/(\.c\$\(OBJ_EXT\):\n\t.*)/$1 $co\$*\$(OBJ_EXT)/;
+	unless ( $t =~ /\.c\$\(OBJ_EXT\)\s*:\n\t.*\Q\$\*\$\(OBJ_EXT\)\E/ ) {
+		$t =~ s/(\.c\$\(OBJ_EXT\)\s*:\n\t.*)/$1 $co\$*\$(OBJ_EXT)/;
 	}
 	return $t;
 }
