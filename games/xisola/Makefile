# New ports collection makefile for:	xisola
# Version required:			1.0
# Date created:				9 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		xisola-1.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=		ports@FreeBSD.org

WRKSRC=			${WRKDIR}/xisola
USE_IMAKE=		yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xisola ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/xisola
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xisola
.endif

.include <bsd.port.mk>
