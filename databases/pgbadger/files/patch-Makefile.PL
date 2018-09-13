--- Makefile.PL.orig	2018-09-13 11:03:46.086169000 +0200
+++ Makefile.PL	2018-09-13 11:03:58.018702000 +0200
@@ -45,13 +45,13 @@
 	echo "=head1 SYNOPSIS" > $@
 	./pgbadger --help >> $@
 	echo "=head1 DESCRIPTION" >> $@
-	sed -i.bak 's/ +$$//g' $@
+	gsed -i.bak 's/ +$$//g' $@
 	rm $@.bak
 
 .PHONY: doc/pgBadger.pod
 doc/pgBadger.pod: doc/synopsis.pod Makefile
-	sed -i.bak '/^=head1 SYNOPSIS/,/^=head1 DESCRIPTION/d' $@
-	sed -i.bak '4r $<' $@
+	gsed -i.bak '/^=head1 SYNOPSIS/,/^=head1 DESCRIPTION/d' $@
+	gsed -i.bak '4r $<' $@
 	rm $@.bak
 EOMAKE
 }
