#
# $FreeBSD$

CFLAGS+=	-DINLINE

COBJS=	compiler/cmdlib.o \
	compiler/hash.o \
	compiler/main.o \
	compiler/pr_comp.o \
	compiler/pr_lex.o \
	compiler/qcc.o

DECOBJS= decompiler/cmdlib.o \
	decompiler/decomp.o \
	decompiler/main.o

.c.o:
	${CC} ${CFLAGS} -o $@ -c $<

all:	c dec

c:	${COBJS}
	${CC} ${LDFLAGS} -o frikqcc $>

dec:	${DECOBJS}
	${CC} ${LDFLAGS} -o frikqcdec $>
