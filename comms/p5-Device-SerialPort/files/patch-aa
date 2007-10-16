--- Makefile.PL.orig	Fri Jul 20 19:27:38 2007
+++ Makefile.PL	Wed Sep 12 15:53:10 2007
@@ -25,8 +25,9 @@
 # testing.
 if (scalar(@SERIALS)>0 && $SERIALS[0] eq "auto") {
 	print "Trying to find a serial port for testing...\n";
-	@SERIALS=( "/dev/ttyS1", "/dev/cua01", "/dev/cua/b", "/dev/tty1",
-		   "/dev/tty.modem" );
+	@SERIALS=( "/dev/ttyU0", "/dev/ucom0", "/dev/ttyd0", "/dev/cuad0",
+		   "/dev/ttyu0", "/dev/cuau0", "/dev/cuaa0", "/dev/ttya",
+		   "/dev/ttyb" );
 	print "(use 'perl Makefile.PL TESTPORT=<DEVICE>' to override this search)\n";
 }
 
