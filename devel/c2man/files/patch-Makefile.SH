--- .vimbk/Makefile.SH.vimbk	Fri Feb 25 03:20:36 2000
+++ Makefile.SH	Fri Aug 17 16:14:51 2001
@@ -25,7 +25,6 @@
 # UNIX makefile for manual page generator
 # Note: any changes made here will be lost next time Configure is run!.
 
-CC=$cc $optimize
 YACC=$yacc $yaccflags
 LEX=$lex $lexflags
 SED=$sed
@@ -42,7 +41,6 @@
 
 mansrc=$mansrc
 manext=$manext
-CFLAGS=$ccflags
 WARNFLAGS=$warnflags
 LDFLAGS=$ldflags
 LIBS=$libs $liblex $libyacc
@@ -71,14 +69,8 @@
 all: c2man c2man.1
 
 install: all
-	$(CP) c2man $(bin)
-	$(CP) c2man.1 $(mansrc)/c2man.$(manext)
-	-mkdir $(privlib)
-	chmod 755 $(privlib)
-	-mkdir $(privlib)/eg
-	chmod 755 $(privlib)/eg
-	$(CP) eg/*.[chly] $(privlib)/eg
-	chmod 755 $(privlib)/eg/*
+	$(BSD_INSTALL_PROGRAM) c2man $(PREFIX)/bin/
+	$(BSD_INSTALL_MAN) c2man.1 $(PREFIX)/man/man1/
 
 uninstall:
 	$(RM) -f $(bin)/c2man $(mansrc)/c2man.$(manext)
