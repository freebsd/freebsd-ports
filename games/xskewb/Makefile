# New ports collection makefile for:	xskewb
# Version required:			5.4.4
# Date created:				25 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		xskewb-5.4.4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=		ports@FreeBSD.org

WRKSRC=			${WRKDIR}/xskewb
USE_IMAKE=		yes
MAN1=			xskewb.1
MANCOMPRESSED=		no

# Not configured to use Motif.
# Optionally edit ${WRKSRC}/Imakefile before build.

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xskewb ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/Skewb.ad ${PREFIX}/lib/X11/app-defaults/Skewb
	@${INSTALL_MAN} ${WRKSRC}/xskewb.man ${PREFIX}/man/man1/xskewb.1

.include <bsd.port.mk>
