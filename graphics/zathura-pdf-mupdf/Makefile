PORTNAME=	zathura-pdf-mupdf
DISTVERSION=	2026.02.03
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-pdf-mupdf/download/

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	MuPDF render PDF plugin for Zathura PDF viewer
WWW=		https://pwmt.org/projects/zathura-pdf-mupdf/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	appstreamcli:devel/appstream \
		zathura:graphics/zathura
LIB_DEPENDS=	libgirara.so:x11-toolkits/girara \
		libmupdf.so:graphics/mupdf
RUN_DEPENDS=	zathura:graphics/zathura

USES=		compiler:c17 desktop-file-utils gnome meson pkgconfig tar:xz
USE_GNOME=	cairo glib20

CONFLICTS_INSTALL=	zathura-pdf-poppler

#MESON_ARGS=	-Dlink-external=true

PLIST_FILES=	lib/zathura/libpdf-mupdf.so \
		share/applications/org.pwmt.zathura-pdf-mupdf.desktop \
		share/metainfo/org.pwmt.zathura-pdf-mupdf.metainfo.xml

post-patch:
	${REINPLACE_CMD} "s@\(cc.find_library(.*\))@\1,dirs:'${PREFIX}/lib')@" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
