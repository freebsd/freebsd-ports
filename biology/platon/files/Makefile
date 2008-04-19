# Makefile for platon
#
# $FreeBSD$

TARGET=	platon
OBJS=	platon.o xdrvr.o
.if ${OSVERSION} >= 400018
FOPT=	${FFLAGS}
.else
FOPT=	${FFLAGS} -Nx800 -NL400 -Nn802
.endif
COPT=	${CFLAGS} -I%%LOCALBASE%%/include
LOPT=	-L%%LOCALBASE%%/lib -lX11

all:	${OBJS}
	${FC} -o ${TARGET} ${OBJS} ${LOPT}

platon.o:	platon.f
	${FC} ${FOPT} -c $<

xdrvr.o:	xdrvr.c
	${CC} ${COPT} -c $<

#f77 -o platon platon.f xdrvr.c -lX11
