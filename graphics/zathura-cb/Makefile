PORTNAME=	zathura-cb
DISTVERSION=	0.1.8
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	https://git.pwmt.org/pwmt/${PORTNAME}/-/archive/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comic book plugin for Zathura PDF viewer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zathura:graphics/zathura
RUN_DEPENDS=	zathura:graphics/zathura

USES=		compiler:c11 desktop-file-utils gnome libarchive meson ninja \
		pkgconfig ssl
USE_GNOME=	glib20 gtk30

PLIST_FILES=	lib/zathura/libcb.so \
		share/appdata/org.pwmt.zathura-cb.metainfo.xml \
		share/applications/org.pwmt.zathura-cb.desktop

pre-configure:
	${REINPLACE_CMD} "s:join_paths(datadir, 'metainfo'):join_paths(datadir, 'appdata'):" ${WRKSRC}/meson.build

.include <bsd.port.mk>
