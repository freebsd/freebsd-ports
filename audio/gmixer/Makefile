# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmixer
PORTVERSION=	0.98c
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cpiazza

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	X11/gtk+ mixer control

ALL_TARGET=	gmixer

USES=		pkgconfig
NO_STAGE=	yes
USE_GNOME=	gtk12
PLIST_FILES=	bin/gmixer share/pixmaps/gmixer.xpm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmixer ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icons/gmixer.xpm ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
