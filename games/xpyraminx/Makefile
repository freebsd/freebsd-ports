# New ports collection makefile for:	xpyraminx
# Version required:			5.4.4
# Date created:				26 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/05/20 07:56:07 tg Exp $
#

DISTNAME=		xpyraminx-5.4.4
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=		andy@icc.surw.chel.su

WRKSRC=			${WRKDIR}/xpyraminx
USE_IMAKE=		yes
MAN1=			xpyraminx.1

# Not configured to use Motif.
# Optionally edit ${WRKSRC}/Imakefile before build.

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xpyraminx ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/Pyraminx.ad ${PREFIX}/lib/X11/app-defaults/Pyraminx
	@ ${INSTALL_MAN} ${WRKSRC}/xpyraminx.man ${PREFIX}/man/man1/xpyraminx.1

.include <bsd.port.mk>
