# Makefile for platon

TARGET=	platon
OBJS=	platon.o xdrvr.o
FOPT=	-Nx800 -NL400 -Nn802
COPT=	-I/usr/X11R6/include
LOPT=	-L/usr/X11R6/lib -lX11 -lf2c

all:	${OBJS}
	${FC} -o ${TARGET} ${OBJS} ${LOPT}

platon.o:	platon.f
	${FC} ${FOPT} -c $<

xdrvr.o:	xdrvr.c
	${CC} ${COPT} -c $<

#f77 -o platon platon.f xdrvr.c -lX11
