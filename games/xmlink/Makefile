# New ports collection makefile for:	xmlink
# Version required:			5.4.4
# Date created:				19 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		xmlink-5.4.4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=		andy@icc.surw.chel.su

WRKSRC=			${WRKDIR}/xmlink
USE_IMAKE=		yes
MAN1=			xmlink.1

# Not configured to use Motif.
# Optionally edit ${WRKSRC}/Imakefile before build.

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xmlink ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/Mlink.ad ${PREFIX}/lib/X11/app-defaults/Mlink
	@ ${INSTALL_MAN} ${WRKSRC}/xmlink.man ${PREFIX}/man/man1/xmlink.1

.include <bsd.port.mk>
