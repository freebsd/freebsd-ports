# New ports collection makefile for:	xtron
# Version required:			1.1a
# Date created:				29 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		xtron-1.1a
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade
EXTRACT_SUFX=		.tgz

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=		yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xtron ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/xtron
	@ ${INSTALL_DATA} ${WRKSRC}/pixmaps/* ${PREFIX}/share/xtron
	@ ${INSTALL_DATA} ${WRKSRC}/xtronrc ${PREFIX}/lib/X11/app-defaults/Tron
	@ ${MKDIR} ${PREFIX}/share/doc/xtron

.if !defined(NOPORTDOCS)
post-install:
.for file in CHANGES COPYING README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xtron
.endfor
.endif

.include <bsd.port.mk>
