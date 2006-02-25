# $FreeBSD$

PROG=	cjktexsty
SRCS=	cjktexsty.l

PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
CFLAGS+=-I${PREFIX}/include
LDADD=	-L${PREFIX}/lib -liconv
NO_MAN=
NOMAN=

.include <bsd.prog.mk>
