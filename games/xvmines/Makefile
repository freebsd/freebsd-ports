# New ports collection makefile for:	xvmines
# Version required:			1.0
# Date created:				18 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	xvmines-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.csd.uch.gr/pub/X11/games/ \
		ftp://ftp.cdrom.com/pub/X11/R5contrib/ \
		ftp://ftp.gwdg.de/pub/x11/x.org/R5contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview \
		olgx.3:${PORTSDIR}/x11-toolkits/xview

USE_IMAKE=	yes
MAN6=		xvmines.6
MANCOMPRESSED=	no

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xvmines ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/xvmines.man ${PREFIX}/man/man6/xvmines.6
	@ ${MKDIR} ${PREFIX}/share/doc/xvmines
	@ ${INSTALL_DATA} ${WRKSRC}/Copyright ${PREFIX}/share/doc/xvmines

.include <bsd.port.mk>
