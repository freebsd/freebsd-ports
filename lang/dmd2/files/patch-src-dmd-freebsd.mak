--- freebsd.mak.orig
+++ freebsd.mak
@@ -3,7 +3,7 @@
 TK=tk
 ROOT=root
 
-MODEL=-m32
+MODEL=
 
 CC=c++ $(MODEL)
 
@@ -40,7 +40,7 @@ DMD_OBJS = \
 	type.o typinf.o util.o var.o version.o strtold.o utf.o staticassert.o \
 	unialpha.o toobj.o toctype.o toelfdebug.o entity.o doc.o macro.o \
 	hdrgen.o delegatize.o aa.o ti_achar.o toir.o interpret.o traits.o \
-	builtin.o clone.o aliasthis.o \
+	builtin.o clone.o aliasthis.o intrange.o \
 	man.o arrayop.o port.o response.o async.o json.o speller.o aav.o unittests.o \
 	imphint.o argtypes.o ti_pvoid.o \
 	libelf.o elfobj.o
@@ -53,7 +53,7 @@ SRC = win32.mak linux.mak osx.mak freebs
 	inifile.c iasm.c module.c scope.c dump.c init.h init.c attrib.h \
 	attrib.c opover.c class.c mangle.c bit.c tocsym.c func.c inline.c \
 	access.c complex_t.h irstate.h irstate.c glue.c msc.c ph.c tk.c \
-	s2ir.c todt.c e2ir.c util.c identifier.h parse.h \
+	s2ir.c todt.c e2ir.c util.c identifier.h parse.h intrange.h \
 	scope.h enum.h import.h mars.h module.h mtype.h dsymbol.h \
 	declaration.h lexer.h expression.h irstate.h statement.h eh.c \
 	utf.h utf.c staticassert.h staticassert.c unialpha.c \
@@ -62,7 +62,7 @@ SRC = win32.mak linux.mak osx.mak freebs
 	delegatize.c toir.h toir.c interpret.c traits.c cppmangle.c \
 	builtin.c clone.c lib.h libomf.c libelf.c libmach.c arrayop.c \
 	aliasthis.h aliasthis.c json.h json.c unittests.c imphint.c \
-	argtypes.c \
+	argtypes.c intrange.c \
 	$C/cdef.h $C/cc.h $C/oper.h $C/ty.h $C/optabgen.c \
 	$C/global.h $C/parser.h $C/code.h $C/type.h $C/dt.h $C/cgcv.h \
 	$C/el.h $C/iasm.h $C/rtlsym.h $C/html.h \
@@ -596,6 +596,7 @@ gcov:
 	gcov utf.c
 	gcov util.c
 	gcov version.c
+	gcov intrange.c
 
 #	gcov hdrgen.c
 #	gcov tocvdebug.c
