# New ports collection makefile for:	xvier
# Version required:			1.0
# Date created:				17 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		xvier
PKGNAME=		xvier-1.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		andy@icc.surw.chel.su

WRKSRC=			${WRKDIR}/${PKGNAME}
USE_IMAKE=		yes
MAN6=			xvier.6
MANCOMPRESSED=		no

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xvier ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xvier_prog ${PREFIX}/libexec
	@ ${INSTALL_DATA} ${WRKSRC}/xvier.man ${PREFIX}/man/man6/xvier.6
	@ ${MKDIR} ${PREFIX}/share/doc/xvier
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xvier

.include <bsd.port.mk>
