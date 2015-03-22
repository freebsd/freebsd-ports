# Makefile for platon
#
# $FreeBSD$

TARGET=	platon
OBJS=	platon.o xdrvr.o
CFLAGS+=-I${LOCALBASE}/include
LDADD=	-L${LOCALBASE}/lib -lX11

all:	${OBJS}
	${FC} -o ${TARGET} ${OBJS} ${LDADD}

#f77 -o platon platon.f xdrvr.c -lX11
