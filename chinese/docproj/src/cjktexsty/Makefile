# $FreeBSD$

PROG=	cjktexsty
SRCS=	cjktexsty.l

PREFIX?=	/usr/local
LOCALBASE?=	${PREFIX}
BINDIR=		${PREFIX}/bin
CFLAGS+=	-I${LOCALBASE}/include
LDADD=		-L${LOCALBASE}/lib -liconv
NO_MAN=
NOMAN=

.include <bsd.prog.mk>
