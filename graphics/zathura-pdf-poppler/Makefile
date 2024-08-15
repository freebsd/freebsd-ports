PORTNAME=	zathura-pdf-poppler
DISTVERSION=	0.3.3
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-pdf-poppler/download/

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Poppler render PDF plugin for Zathura PDF viewer
WWW=		https://pwmt.org/projects/zathura-pdf-poppler/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		zathura>=0.5.3:graphics/zathura
LIB_DEPENDS=	libgirara-gtk3.so:x11-toolkits/girara \
		libpoppler-glib.so:graphics/poppler-glib
RUN_DEPENDS=	zathura>=0.5.3:graphics/zathura

USES=		compiler:c11 desktop-file-utils gnome meson ninja pkgconfig \
		tar:xz
USE_GNOME=	cairo glib20

CONFLICTS_INSTALL=	zathura-pdf-mupdf

PLIST_FILES=	lib/zathura/libpdf-poppler.so \
		share/appdata/org.pwmt.zathura-pdf-poppler.metainfo.xml \
		share/applications/org.pwmt.zathura-pdf-poppler.desktop

pre-configure:
	@${REINPLACE_CMD} "s:join_paths(datadir, 'metainfo'):join_paths(datadir, 'appdata'):" ${WRKSRC}/meson.build

.include <bsd.port.mk>
