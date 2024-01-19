PORTNAME=	zathura-pdf-poppler
DISTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://git.pwmt.org/pwmt/${PORTNAME}/-/archive/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Poppler render PDF plugin for Zathura PDF viewer
WWW=		https://pwmt.org/projects/zathura/plugins/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zathura:graphics/zathura
LIB_DEPENDS=	libgirara-gtk3.so:x11-toolkits/girara \
		libpoppler-glib.so:graphics/poppler-glib
RUN_DEPENDS=	zathura:graphics/zathura

USES=		compiler:c11 desktop-file-utils gnome meson ninja pkgconfig
USE_GNOME=	cairo glib20 gtk30
USE_LDCONFIG=	${PREFIX}/lib/zathura

CONFLICTS=	zathura-pdf-mupdf

PLIST_FILES=	lib/zathura/libpdf-poppler.so \
		share/appdata/org.pwmt.zathura-pdf-poppler.metainfo.xml \
		share/applications/org.pwmt.zathura-pdf-poppler.desktop

pre-configure:
	@${REINPLACE_CMD} "s:join_paths(datadir, 'metainfo'):join_paths(datadir, 'appdata'):" ${WRKSRC}/meson.build

.include <bsd.port.mk>
