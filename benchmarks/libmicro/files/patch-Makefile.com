--- Makefile.com.orig	Sat Aug  6 14:02:15 2005
+++ Makefile.com	Sat Aug  6 14:05:15 2005
@@ -44,7 +44,7 @@
 COMPILER_VERSION_CMD_gcc=gcc -dumpversion
 COMPILER_VERSION_CMD=$(COMPILER_VERSION_CMD_$(CC))
 
-default: $(ALL) tattle
+all: $(ALL) tattle
 
 cstyle:	
 	for file in $(ALL:%=../%.c) $(EXTRA_CFILES:%=../%) ; \
@@ -56,10 +56,10 @@
 
 
 $(EXTRA_CFILES:%.c=%.lint):
-	$(LINT) ../$(@:%.lint=%.c) -I. -mu -lc libmicro.ln -lm
+	$(LINT) ../$(@:%.lint=%.c) -I. -mu -lc libmicro.ln -lm $(PTHREAD_LIBS)
 
 %.lint:	../%.c libmicro.ln
-	$(LINT) -mu $(CPPFLAGS) $< libmicro.ln -lpthread -lsocket -lnsl -lm
+	$(LINT) -mu $(CPPFLAGS) $< libmicro.ln -lm $(PTHREAD_LIBS)
 
 %.o:	../%.c
 	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
@@ -109,13 +109,13 @@
 	echo "char * compiler_version = \""`$(COMPILER_VERSION_CMD)`"\";" > tattle.h
 	echo "char * CC = \""$(CC)"\";" >> tattle.h
 	echo "char * extra_compiler_flags = \""$(extra_CFLAGS)"\";" >> tattle.h
-	$(CC) -o tattle $(CFLAGS) -I. ../tattle.c libmicro.a -lrt -lm
+	$(CC) -o tattle $(CFLAGS) -I. ../tattle.c libmicro.a -lm $(PTHREAD_LIBS)
 
 $(ELIDED_BENCHMARKS):	../elided.c
 	$(CC) -o $(@) ../elided.c
 
 %: libmicro.a %.o 
-	$(CC) -o $(@) $(@).o $($(@)_EXTRA_DEPS) $(CFLAGS) libmicro.a $($(@)_EXTRA_LIBS) $(EXTRA_LIBS) -lpthread -lm
+	$(CC) -o $(@) $(@).o $($(@)_EXTRA_DEPS) $(CFLAGS) libmicro.a $($(@)_EXTRA_LIBS) $(EXTRA_LIBS) -lm $(PTHREAD_LIBS)
 
 exec:	exec_bin
 
