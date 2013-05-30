#
# $FreeBSD$
#

all: sq usq

sq: sq.o tr1.o tr2.o sqio.o
	${CC} ${CFLAGS} -o $@ $>

usq: usq.o utr.o
	${CC} ${CFLAGS} -o $@ $>
