# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=		liblug
PORTVERSION=		1.0.6
PORTREVISION=		5
CATEGORIES=		graphics
MASTER_SITES=		SUNSITE/libs/graphics

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Multi-format graphics manipulation library

LIB_DEPENDS=		libtiff.so:graphics/tiff

PLIST_FILES=		lib/liblug.a
USE_XORG=		x11
CFLAGS+=		-Wno-return-type

WRKSRC=			${WRKDIR}/lug
MAKEFILE=		Makefile.linux
USE_LDCONFIG=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|-DiTIFF|-DiTIFF -DTIFF_VERSION=TIFF_VERSION_CLASSIC|' \
		${WRKSRC}/Makefile.linux

.include <bsd.port.mk>
