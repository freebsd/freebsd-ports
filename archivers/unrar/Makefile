# New ports collection makefile for:    unrar
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	unrar
PORTVERSION=    3.10b1
CATEGORIES=	archivers
MASTER_SITES=	http://files2.rarlab.com/rar/
DISTNAME=       unrarsrc-3.1.0

MAINTAINER=	ache@FreeBSD.org

WRKSRC=         ${WRKDIR}/unrar

ALL_TARGET=	makeunrar

post-patch:
	@${SED} -e 's|c++|${CXX}|g' -e 's|-O2|${CXXFLAGS}|g' \
		${WRKSRC}/makefile.gcc > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
