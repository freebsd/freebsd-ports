# New ports collection makefile for:	teapot
# Date created:				7 January 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	teapot
PORTVERSION=	1.07
CATEGORIES=	deskutils
MASTER_SITES=	http://www.moria.de/~michael/teapot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-screen curses based spread sheet program

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="" LIBS="-lcurses -lm" \
		MAKEDEPEND=""
ALL_TARGET=	teapot
MAN1=		teapot.1

EXAMPLES=	examples/asqrt examples/asqrt.README examples/blink \
		examples/counter examples/counter.README examples/life \
		examples/life.README examples/graphtest.sh examples/sqrt \
		examples/sqrt.README
MYPORTDOCS=	doc/teapot.doc doc/teapot.html doc/teapot.ps

post-build:
	@cd ${WRKSRC}/doc && ${MAKE} teapot.doc teapot.html teapot.ps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/teapot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/teapot.1.en ${MANPREFIX}/man/man1/teapot.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
	@${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
