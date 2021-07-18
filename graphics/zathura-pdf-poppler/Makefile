# Created by: Mike Krutov <neko@takino.org>

PORTNAME=	zathura-pdf-poppler
DISTVERSION=	0.3.0
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	https://git.pwmt.org/pwmt/${PORTNAME}/-/archive/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Poppler render PDF plugin for Zathura PDF viewer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
BUILD_DEPENDS=	zathura:graphics/zathura
RUN_DEPENDS=	zathura:graphics/zathura

USES=		compiler:c11 desktop-file-utils gnome meson ninja pkgconfig
USE_GNOME=	glib20 gtk30

CONFLICTS=	zathura-pdf-mupdf-[0-9]*

PLIST_FILES=	lib/zathura/libpdf-poppler.so \
		share/appdata/org.pwmt.zathura-pdf-poppler.metainfo.xml \
		share/applications/org.pwmt.zathura-pdf-poppler.desktop

pre-configure:
	@${REINPLACE_CMD} "s:join_paths(datadir, 'metainfo'):join_paths(datadir, 'appdata'):" ${WRKSRC}/meson.build

.include <bsd.port.mk>
