# $FreeBSD$

PROG=	cjktexsty
SRCS=	cjktexsty.l

PREFIX?=	/usr/local
LOCALBASE?=	${PREFIX}
BINDIR=		${PREFIX}/bin
CFLAGS+=	-I${LOCALBASE}/include
LDADD=		-L${LOCALBASE}/lib -liconv
MAN=

.if defined(BSD_INSTALL_PROGRAM)
install:
	${BSD_INSTALL_PROGRAM} ${PROG} ${DESTDIR}${BINDIR}/${PROGNAME}
.endif

.include <bsd.prog.mk>
