#
# $FreeBSD$
#

BIN=	umark

INCS=	`pkg-config gtk+-2.0 --cflags`
DEFS=	-DPACKAGE_DATA_DIR=\"${PREFIX}/share\" -DPACKAGE=\"${BIN}\"
LIBS=	`pkg-config gtk+-2.0 --libs`

OBJS = \
	callbacks.o \
	interface.o \
	main.o \
	support.o \

.c.o:
	${CC} ${CFLAGS} ${DEFS} ${INCS} -c $< -o $*.o

all:	${OBJS}
	${CC} ${CFLAGS} -o ${BIN} ${OBJS} ${LIBS}

clean:
	-rm -f *.o *.core
