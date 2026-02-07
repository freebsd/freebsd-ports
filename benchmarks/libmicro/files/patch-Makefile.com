--- Makefile.com.orig	2011-05-11 00:58:23 UTC
+++ Makefile.com
@@ -42,7 +42,7 @@ COMPILER_VERSION_CMD_cc=cc -V 2>&1 | egr
 COMPILER_VERSION_CMD_gcc=gcc -dumpversion
 COMPILER_VERSION_CMD=$(COMPILER_VERSION_CMD_$(CC))
 
-default: $(ALL) tattle
+all: $(ALL) tattle
 
 cstyle:	
 	for file in $(ALL:%=../%.c) $(EXTRA_CFILES:%=../%) ; \
@@ -54,10 +54,10 @@ lint:	libmicro.ln $(ALL:%=%.lint) $(EXTR
 
 
 $(EXTRA_CFILES:%.c=%.lint):
-	$(LINT) ../$(@:%.lint=%.c) -I. -mu -lc libmicro.ln -lm
+	$(LINT) ../$(@:%.lint=%.c) -I. -mu -lc libmicro.ln -lm -lpthread
 
 %.lint:	../%.c libmicro.ln
-	$(LINT) -mu $(CPPFLAGS) $< libmicro.ln -lpthread -lsocket -lnsl -lm
+	$(LINT) -mu $(CPPFLAGS) $< libmicro.ln -lpthread -lm
 
 %.o:	../%.c
 	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
@@ -107,7 +107,7 @@ tattle:		../tattle.c	libmicro.a
 	echo "char * compiler_version = \""`$(COMPILER_VERSION_CMD)`"\";" > tattle.h
 	echo "char * CC = \""$(CC)"\";" >> tattle.h
 	echo "char * extra_compiler_flags = \""$(extra_CFLAGS)"\";" >> tattle.h
-	$(CC) -o tattle $(CFLAGS) -I. ../tattle.c libmicro.a -lrt -lm
+	$(CC) -o tattle $(CFLAGS) -I. ../tattle.c libmicro.a -lpthread -lm
 
 $(ELIDED_BENCHMARKS):	../elided.c
 	$(CC) -o $(@) ../elided.c
