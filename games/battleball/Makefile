# New ports collection makefile for:	battleball
# Version required:			2.0
# Date created:				18 December 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	battleball.20.src
PKGNAME=	battleball-2.0
CATEGORIES=	games
MASTER_SITES=	http://www.cs.utexas.edu/users/pahardin/

MAINTAINER=	will@FreeBSD.org

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/bb-2.0

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/battleball ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/battleball
.for file in CHANGELOG README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/battleball
.endfor
.endif

.include <bsd.port.mk>
