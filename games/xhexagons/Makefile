# New ports collection makefile for:	xhexagons
# Version required:			5.4.4
# Date created:				20 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		xhexagons-5.4.4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=		ports@FreeBSD.org

WRKSRC=			${WRKDIR}/xhexagons
USE_IMAKE=		yes
MAN1=			xhexagons.1
MANCOMPRESSED=		no

# Not configured to use Motif.
# Optionally edit ${WRKSRC}/Imakefile before build.

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xhexagons ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/Hexagons.ad ${PREFIX}/lib/X11/app-defaults/Hexagons
	@${INSTALL_MAN} ${WRKSRC}/xhexagons.man ${PREFIX}/man/man1/xhexagons.1

.include <bsd.port.mk>
