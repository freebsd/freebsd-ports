# New ports collection makefile for:	xoids
# Version required:			1.5
# Date created:				16 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/04/27 05:01:10 mph Exp $
#

DISTNAME=		xoids-1.5
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=		yes
MAN6=			xoids.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xoids ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/xoids.1x ${PREFIX}/man/man6/xoids.6
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/xoids
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xoids
.endif

.include <bsd.port.mk>
