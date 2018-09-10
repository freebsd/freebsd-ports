--- Makefile.PL.orig	2018-09-10 08:43:15 UTC
+++ Makefile.PL
@@ -45,12 +45,12 @@ doc/synopsis.pod: Makefile pgbadger
 	echo "=head1 SYNOPSIS" > $@
 	./pgbadger --help >> $@
 	echo "=head1 DESCRIPTION" >> $@
-	sed -i 's/ +$$//g' $@
+	gsed -i 's/ +$$//g' $@
 
 .PHONY: doc/pgBadger.pod
 doc/pgBadger.pod: doc/synopsis.pod Makefile
-	sed -i '/^=head1 SYNOPSIS/,/^=head1 DESCRIPTION/d' $@
-	sed -i '4r $<' $@
+	gsed -i '/^=head1 SYNOPSIS/,/^=head1 DESCRIPTION/d' $@
+	gsed -i '4r $<' $@
 EOMAKE
 }
 
