# New ports collection makefile for:	affenspiel
# Version required:			1.0
# Date created:				2 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		affenspiel-1.0
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
EXTRACT_SUFX=		.tgz

MAINTAINER=		andy@icc.surw.chel.su

WRKSRC=			${WRKDIR}/affenspiel
USE_X11=		yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/affenspiel ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/affenspiel
	@ ${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/affenspiel
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/affenspiel
.endif

.include <bsd.port.mk>
