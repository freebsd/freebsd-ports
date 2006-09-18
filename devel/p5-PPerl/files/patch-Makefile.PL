--- Makefile.PL.orig	Fri Sep 15 21:59:08 2006
+++ Makefile.PL	Fri Sep 15 21:59:24 2006
@@ -69,7 +69,7 @@
 main.o: Makefile main.c pperl.h
 
 pperl: main.o pass_fd.o
-\t\$(CC) \$(CFLAGS) \$(LDFLAGS) \$(DEFINE) -o pperl main.o pass_fd.o $Config{libs}
+\t\$(CC) \$(CCFLAGS) \$(OPTIMIZE) \$(LDFLAGS) \$(DEFINE) -o pperl main.o pass_fd.o $Config{libs}
 
 pass_fd.c: pass_fd.h
 
