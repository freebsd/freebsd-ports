# New ports collection makefile for:	affenspiel
# Date created:				2 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	affenspiel
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/affenspiel
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/affenspiel ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/affenspiel
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/affenspiel
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/affenspiel
.endif

.include <bsd.port.mk>
