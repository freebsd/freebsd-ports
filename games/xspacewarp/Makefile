# New ports collection makefile for:	xspacewarp
# Version required:			1.2
# Date created:				16 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		xspacewarp-1.2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=		ports@FreeBSD.org

USE_IMAKE=		yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xspacewarp ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/XSpacewarp.app_def ${X11BASE}/lib/X11/app-defaults/XSpacewarp

.include <bsd.port.mk>
