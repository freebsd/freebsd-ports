# New ports collection makefile for:	xoct
# Version required:			5.4.4
# Date created:				28 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/05/20 07:52:39 tg Exp $
#

DISTNAME=		xoct-5.4.4
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=		andy@icc.surw.chel.su

WRKSRC=			${WRKDIR}/xoct
USE_IMAKE=		yes
MAN1=			xoct.1

# Not configured to use Motif.
# Optionally edit ${WRKSRC}/Imakefile before build.

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xoct ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/Oct.ad ${PREFIX}/lib/X11/app-defaults/Oct
	@ ${INSTALL_MAN} ${WRKSRC}/xoct.man ${PREFIX}/man/man1/xoct.1

.include <bsd.port.mk>
