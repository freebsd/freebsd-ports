# New ports collection makefile for:	teapot
# Date created:				7 January 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	teapot
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.moria.de/~michael/teapot/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	teapot
MAN1=		teapot.1

EXAMPLES=	examples/asqrt examples/asqrt.README examples/blink \
		examples/counter examples/counter.README examples/life \
		examples/life.README examples/sqrt examples/sqrt.README
PORTDOCS=	README-de.html README-en.html README-nl.html \
		doc/teapot.doc doc/teapot.html doc/teapot.ps

post-build:
	@ cd ${WRKSRC}/doc && ${MAKE} teapot.doc teapot.html teapot.ps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/teapot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/teapot.1.en ${PREFIX}/man/man1/teapot.1
	@${MKDIR} ${PREFIX}/share/examples/teapot
.for file in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/examples/teapot
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/teapot
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/teapot
.endfor
.endif

.include <bsd.port.mk>
