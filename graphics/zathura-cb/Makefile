# $FreeBSD$

PORTNAME=	zathura-cb
PORTVERSION=	0.1.8
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-cb/download/ \
		http://www.madpilot.net/~mad/pwmt.org/

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Comic book plugin for Zathura PDF viewer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zathura:graphics/zathura
RUN_DEPENDS=	zathura:graphics/zathura

USES=		meson ninja compiler:c11 desktop-file-utils pkgconfig libarchive ssl tar:xz
USE_GNOME=	glib20 gtk30

PLIST_FILES=	lib/zathura/libcb.so \
		share/appdata/org.pwmt.zathura-cb.metainfo.xml \
		share/applications/org.pwmt.zathura-cb.desktop

pre-configure:
	${REINPLACE_CMD} "s:join_paths(datadir, 'metainfo'):join_paths(datadir, 'appdata'):" ${WRKSRC}/meson.build

.include <bsd.port.mk>
