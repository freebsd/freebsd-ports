PORTNAME=	zathura-cb
DISTVERSION=	0.1.10
CATEGORIES=	graphics
MASTER_SITES=	https://git.pwmt.org/pwmt/${PORTNAME}/-/archive/${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Comic book plugin for Zathura PDF viewer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zathura:graphics/zathura
LIB_DEPENDS=	libgirara-gtk3.so:x11-toolkits/girara
RUN_DEPENDS=	zathura:graphics/zathura

# testing without USES=ssl
USES=		compiler:c11 desktop-file-utils gnome libarchive meson ninja \
		pkgconfig
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
USE_LDCONFIG=	yes

PLIST_FILES=	lib/zathura/libcb.so \
		share/appdata/org.pwmt.zathura-cb.metainfo.xml \
		share/applications/org.pwmt.zathura-cb.desktop

pre-configure:
	${REINPLACE_CMD} "s:join_paths(datadir, 'metainfo'):join_paths(datadir, 'appdata'):" ${WRKSRC}/meson.build

.include <bsd.port.mk>
