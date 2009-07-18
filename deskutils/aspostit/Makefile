# New ports collection makefile for:   ASPostIt
# Date created:        2 January 1999
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aspostit
PORTVERSION=	1.3
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_AFTERSTEP}
MASTER_SITE_SUBDIR=	apps/aspostit

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An AfterStep dockable version of XPostIt

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg/

USE_XORG=	xpm xaw xext x11
USE_GMAKE=	yes

GNU_CONFIGURE=	yes

MAN1=		aspostit.1
PLIST_FILES=	bin/aspostit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aspostit ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/aspostit.man ${PREFIX}/man/man1/aspostit.1

.include <bsd.port.mk>
