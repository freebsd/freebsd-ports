--- linux.mak.orig	Sat Jan 15 19:59:27 2005
+++ linux.mak	Sat Jan 15 19:59:20 2005
@@ -1,5 +1,4 @@
-# for Linux/DJGPP
-CFLAGS = -g -O2 -Wall
+CFLAGS += -Dstricmp=strcasecmp -Dstrcmpi=strcasecmp
 
 EXES = qcc
 
@@ -21,8 +20,8 @@
 clean:
 	rm -f *.o *~ $(EXES)
 
-.c.o: ; gcc -c $(CFLAGS) -o $@ $*.c
+.c.o: ; $(CC) -c $(CFLAGS) -o $@ $*.c
 
 QCCFILES = qcc.o pr_lex.o pr_comp.o cmdlib.o l_log.o l_memory.o l_script.o l_precomp.o
 qcc : $(QCCFILES)
-        gcc -o qcc $(QCCFILES)
+	$(CC) -o qcc $(QCCFILES)
