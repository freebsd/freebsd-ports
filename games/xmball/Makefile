# New ports collection makefile for:	xmball
# Version required:			5.4.4
# Date created:				21 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		xmball-5.4.4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=		andy@icc.surw.chel.su

WRKSRC=			${WRKDIR}/xmball
USE_IMAKE=		yes
MAN1=			xmball.1
MANCOMPRESSED=		no

# Not configured to use Motif.
# Optionally edit ${WRKSRC}/Imakefile before build.

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xmball ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/Mball.ad ${PREFIX}/lib/X11/app-defaults/Mball
	@${INSTALL_MAN} ${WRKSRC}/xmball.man ${PREFIX}/man/man1/xmball.1

.include <bsd.port.mk>
