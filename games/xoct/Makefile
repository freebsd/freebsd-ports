# New ports collection makefile for:	xoct
# Version required:			5.4.4
# Date created:				28 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		xoct-5.4.4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=		ports@FreeBSD.org

WRKSRC=			${WRKDIR}/xoct
USE_IMAKE=		yes
MAN1=			xoct.1
MANCOMPRESSED=		no

# Not configured to use Motif.
# Optionally edit ${WRKSRC}/Imakefile before build.

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xoct ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/Oct.ad ${PREFIX}/lib/X11/app-defaults/Oct
	@ ${INSTALL_MAN} ${WRKSRC}/xoct.man ${PREFIX}/man/man1/xoct.1

.include <bsd.port.mk>
