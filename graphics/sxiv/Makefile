# Created by: Solène RAPENNE <solene@bsd.zplay.eu>
# $FreeBSD$

PORTNAME=	sxiv
PORTVERSION=	25
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	solene@bsd.zplay.eu
COMMENT=	Lightweight image viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libgif.so:graphics/giflib \
		libImlib2.so:graphics/imlib2

USES=		gmake localbase:ldflags pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	muennich
USE_XORG=	x11 xft

PLIST_FILES=	bin/sxiv \
		man/man1/sxiv.1.gz \
		share/sxiv/exec/image-info \
		share/sxiv/exec/key-handler

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sxiv

.include <bsd.port.mk>
