# New ports collection makefile for:	xvmines
# Date created:				18 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xvmines
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.csd.uch.gr/pub/X11/games/ \
		ftp://ftp.x.org/R5contrib/ \
		ftp://ftp.freesoftware.com/pub/X11/R5contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

USE_IMAKE=	yes
MAN6=		xvmines.6
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xvmines ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xvmines.man ${PREFIX}/man/man6/xvmines.6
	@${MKDIR} ${PREFIX}/share/doc/xvmines
	${INSTALL_DATA} ${WRKSRC}/Copyright ${PREFIX}/share/doc/xvmines

.include <bsd.port.mk>
