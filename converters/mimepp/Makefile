# New ports collection makefile for:	mimepp
# Date created:				3 July 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	mimepp
PORTVERSION=	1.3.3
CATEGORIES=	converters
MASTER_SITES=	http://www.hunnysoft.com/mimepp/

MAINTAINER=	ports@FreeBSD.org

MAKEFILE=	makefile-unix
ALL_TARGET=	default

do-install:
	${INSTALL_DATA} ${WRKSRC}/dev/*.a ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/mimepp
	${INSTALL_DATA} ${WRKSRC}/src/mimepp/*.h ${PREFIX}/include/mimepp
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mimepp
	${TAR} -C ${WRKSRC}/doc -cf - . | \
		${TAR} -C ${PREFIX}/share/doc/mimepp -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/mimepp
	@${MKDIR} ${PREFIX}/share/examples/mimepp
	${TAR} -C ${WRKSRC}/examples -cf - . | \
		${TAR} -C ${PREFIX}/share/examples/mimepp -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/mimepp
.endif

.include <bsd.port.mk>
