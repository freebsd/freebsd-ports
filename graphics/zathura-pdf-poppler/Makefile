PORTNAME=	zathura-pdf-poppler
DISTVERSION=	0.3.4
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-pdf-poppler/download/

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Poppler render PDF plugin for Zathura PDF viewer
WWW=		https://pwmt.org/projects/zathura-pdf-poppler/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	appstreamcli:devel/appstream \
		zathura:graphics/zathura
LIB_DEPENDS=	libgirara-gtk3.so:x11-toolkits/girara \
		libpoppler-glib.so:graphics/poppler-glib
RUN_DEPENDS=	zathura:graphics/zathura

USES=		compiler:c17 desktop-file-utils gnome meson pkgconfig tar:xz
USE_GNOME=	cairo glib20

CONFLICTS_INSTALL=	zathura-pdf-mupdf

PLIST_FILES=	lib/zathura/libpdf-poppler.so \
		share/applications/org.pwmt.zathura-pdf-poppler.desktop \
		share/metainfo/org.pwmt.zathura-pdf-poppler.metainfo.xml

.include <bsd.port.mk>
