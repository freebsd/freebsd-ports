# New ports collection makefile for:	CaribbeanStud
# Version required:			1.0
# Date created:				4 July 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		CS
PKGNAME=		CaribbeanStud-1.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=		ports@FreeBSD.org

MAKEFILE=		Xmakefile
REQUIRES_MOTIF=		yes
USE_X_PREFIX=		yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/CaribbeanStud ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/CaribbeanStud.res ${PREFIX}/lib/X11/app-defaults/CaribbeanStud
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/CaribbeanStud
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/CaribbeanStud
	@ ${INSTALL_DATA} ${WRKSRC}/class.ps ${PREFIX}/share/doc/CaribbeanStud
.endif

.include <bsd.port.mk>
