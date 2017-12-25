# Created by: Alexander Y. Grigoryev <alexander.4mail@gmail.com>
# $FreeBSD$

PORTNAME=	zathura-djvu
PORTVERSION=	0.2.6
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura/plugins/download/ \
		http://www.madpilot.net/~mad/pwmt.org/

MAINTAINER=	alexander.4mail@gmail.com
COMMENT=	DjVu support for zathura

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
BUILD_DEPENDS=	zathura:graphics/zathura
RUN_DEPENDS=	zathura:graphics/zathura

PLIST_FILES=	lib/zathura/djvu.so share/applications/zathura-djvu.desktop

USE_GNOME=	glib20 gtk30
USES=		compiler:c11 desktop-file-utils gmake pkgconfig

PLIST_FILES=	lib/zathura/djvu.so \
		share/applications/zathura-djvu.desktop

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/zathura/djvu.so

.include <bsd.port.mk>
