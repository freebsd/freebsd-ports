# Created by: Alexander Y. Grigoryev <alexander.4mail@gmail.com>
# $FreeBSD$

PORTNAME=	zathura-djvu
DISTVERSION=	0.2.9
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://git.pwmt.org/pwmt/${PORTNAME}/-/archive/${DISTVERSION}/

MAINTAINER=	alexander.4mail@gmail.com
COMMENT=	DjVu support for zathura

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
BUILD_DEPENDS=	zathura:graphics/zathura
RUN_DEPENDS=	zathura:graphics/zathura

USES=		compiler:c11 desktop-file-utils gnome meson ninja pkgconfig

USE_GNOME=	glib20 gtk30

PLIST_FILES=	lib/zathura/libdjvu.so \
		share/appdata/org.pwmt.zathura-djvu.metainfo.xml \
		share/applications/org.pwmt.zathura-djvu.desktop

pre-configure:
	@${REINPLACE_CMD} "s:join_paths(datadir, 'metainfo'):join_paths(datadir, 'appdata'):" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
