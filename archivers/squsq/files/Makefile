#
# $FreeBSD$
#

all: sq usq

sq: sq.o tr1.o tr2.o sqio.o
	${CC} -o $@ $>

usq: usq.o utr.o
	${CC} -o $@ $>
