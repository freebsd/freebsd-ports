# New ports collection makefile for:	mimepp
# Date created:				3 July 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		mimepp
PORTVERSION=		1.2.4
CATEGORIES=		converters
MASTER_SITES=		http://www.hunnysoft.com/mimepp/

MAINTAINER=		ports@FreeBSD.org

MAKEFILE=		makefile-unix
ALL_TARGET=		default

do-install:
	${INSTALL_DATA} ${WRKSRC}/dev/*.a ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/mimepp
	${INSTALL_DATA} ${WRKSRC}/src/mimepp/*.h ${PREFIX}/include/mimepp
	@${MKDIR} ${PREFIX}/share/examples/mimepp
	${INSTALL_DATA} ${WRKSRC}/examples/*.cpp ${PREFIX}/share/examples/mimepp
	${INSTALL_DATA} ${WRKSRC}/examples/*.h ${PREFIX}/share/examples/mimepp
	${INSTALL_DATA} ${WRKSRC}/examples/*.txt ${PREFIX}/share/examples/mimepp
	${INSTALL_DATA} ${WRKSRC}/examples/makefile-unix ${PREFIX}/share/examples/mimepp
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mimepp
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/mimepp
.endif

.include <bsd.port.mk>
