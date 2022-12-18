PORTNAME=	zathura-pdf-mupdf
DISTVERSION=	0.4.0
CATEGORIES=	graphics
MASTER_SITES=	https://git.pwmt.org/pwmt/${PORTNAME}/-/archive/${DISTVERSION}/ \
		http://freebsd.uzsolt.hu/src/

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	MuPDF render PDF plugin for Zathura PDF viewer
WWW=		https://pwmt.org/projects/zathura-pdf-mupdf/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zathura:graphics/zathura
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgirara-gtk3.so:x11-toolkits/girara \
		libharfbuzz.so:print/harfbuzz \
		libjbig2dec.so:graphics/jbig2dec \
		libmupdf.so:graphics/mupdf \
		libopenjp2.so:graphics/openjpeg
RUN_DEPENDS=	zathura:graphics/zathura

USES=		compiler:c11 desktop-file-utils gnome jpeg meson pkgconfig
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
USE_LDCONFIG=	${PREFIX}/lib/zathura

CONFLICTS_INSTALL=	zathura-pdf-poppler

#MESON_ARGS=	-Dlink-external=true

PLIST_FILES=	lib/zathura/libpdf-mupdf.so \
		share/applications/org.pwmt.zathura-pdf-mupdf.desktop \
		share/metainfo/org.pwmt.zathura-pdf-mupdf.metainfo.xml

post-patch:
	${REINPLACE_CMD} "s@\(cc.find_library(.*\))@\1,dirs:'${PREFIX}/lib')@" \
		${WRKSRC}/meson.build
	${REINPLACE_CMD} "s@join_paths(datadir, \
		'metainfo')@join_paths(datadir, 'appdata')@" ${WRKSRC}/meson.build

.include <bsd.port.mk>
