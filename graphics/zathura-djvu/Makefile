# Created by: Alexander Y. Grigoryev <alexander.4mail@gmail.com>
# $FreeBSD$

PORTNAME=	zathura-djvu
PORTVERSION=	0.2.4
CATEGORIES=	graphics
MASTER_SITES=	http://pwmt.org/projects/zathura/plugins/download/

MAINTAINER=	alexander.4mail@gmail.com
COMMENT=	DjVu support for zathura

LICENSE=	zlib
LICENSE_NAME=	zlib license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libdjvulibre.so:${PORTSDIR}/graphics/djvulibre
BUILD_DEPENDS=	zathura:${PORTSDIR}/graphics/zathura
RUN_DEPENDS=	zathura:${PORTSDIR}/graphics/zathura

PLIST_FILES=	lib/zathura/djvu.so share/applications/zathura-djvu.desktop

USE_GNOME=	glib20 gtk30
USES=		desktop-file-utils gmake pkgconfig

PLIST_FILES=	lib/zathura/djvu.so \
		share/applications/zathura-djvu.desktop

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/zathura/djvu.so

.include <bsd.port.mk>
