# New ports collection makefile for:	xpanex
# Version required:			5.4.4
# Date created:				27 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		xpanex-5.4.4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=		andy@icc.surw.chel.su

WRKSRC=			${WRKDIR}/xpanex
USE_IMAKE=		yes
MAN1=			xpanex.1
MANCOMPRESSED=		no

# Not configured to use Motif.
# Optionally edit ${WRKSRC}/Imakefile before build.

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xpanex ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/Panex.ad ${PREFIX}/lib/X11/app-defaults/Panex
	@ ${INSTALL_MAN} ${WRKSRC}/xpanex.man ${PREFIX}/man/man1/xpanex.1

.include <bsd.port.mk>
