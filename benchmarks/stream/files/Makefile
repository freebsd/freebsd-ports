# $FreeBSD$
# stream didn't come with a makefile

CFLAGS+=	-Wall -pedantic -ansi -pipe
BINOWN=	root
BINGRP=	wheel
BINMODE=	0555
INSTALLDIR=	${PREFIX}/bin

# season to flavor, see the stream docs
NSIZE=	1000000

#
all: stream_d.o second_cpu.o
	${CC} -o stream stream_d.o second_cpu.o -lm

stream_d.o: stream_d.c
	${CC} ${CFLAGS} -DNSIZE=${NSIZE} -c stream_d.c

second_cpu.o: second_cpu.c
	${CC} ${CFLAGS} -c second_cpu.c

install:
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} stream ${INSTALLDIR}
