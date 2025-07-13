--- Makefile.PL.orig	2025-03-16 11:52:30 UTC
+++ Makefile.PL
@@ -55,13 +55,13 @@ doc/synopsis.pod: Makefile pgbadger
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
