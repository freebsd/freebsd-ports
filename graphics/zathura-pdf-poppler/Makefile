# Created by: Mike Krutov <neko@takino.org>
# $FreeBSD$

PORTNAME=	zathura-pdf-poppler
PORTVERSION=	0.2.6
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://pwmt.org/projects/zathura/plugins/download/

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Poppler render PDF plugin for Zathura PDF viewer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
BUILD_DEPENDS=	zathura:graphics/zathura
RUN_DEPENDS=	zathura:graphics/zathura

USE_GNOME=	glib20 gtk30
USES=		compiler:c11 desktop-file-utils gmake pkgconfig

CONFLICTS=	zathura-pdf-mupdf-[0-9]*

PLIST_FILES=	lib/zathura/pdf.so \
		share/appdata/zathura-pdf-poppler.metainfo.xml \
		share/applications/zathura-pdf-poppler.desktop

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/zathura/pdf.so

.include <bsd.port.mk>
