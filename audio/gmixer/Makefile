# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmixer
PORTVERSION=	0.98c
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	LOCAL/cpiazza

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11/gtk+ mixer control

ALL_TARGET=	gmixer

USES=		pkgconfig
USE_GNOME=	gtk12
PLIST_FILES=	bin/gmixer share/pixmaps/gmixer.xpm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmixer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icons/gmixer.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
