PORTNAME=	yacreader
DISTVERSION=	9.15.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/YACReader/${PORTNAME}/releases/download/${DISTVERSION}/
EXTRACT_SUFX=	-src.tar.xz

PATCH_SITES=	https://github.com/YACReader/${PORTNAME}/commit/
PATCHFILES+=	254652f03ec648423c9488929dc62fb3f4b817c7.patch:-p1 # Fix build with Qt >= 6.9.0
PATCHFILES+=	6e0e6f3bc39ddc4d7241f4f946088291410feb50.patch:-p1 # Fix build with Qt >= 6.9.0

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Yet another comic reader
WWW=		https://www.yacreader.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		compiler:c++17-lang desktop-file-utils pkgconfig qmake qt:6 tar:xz
USE_QT=		5compat base declarative multimedia svg tools:build

OPTIONS_DEFINE=	ARCHIVE OPENGL POPPLER
OPTIONS_DEFAULT=OPENGL POPPLER

ARCHIVE_DESC=		libarchive instead of unarr for reading compressed formats
ARCHIVE_USES=		libarchive
ARCHIVE_QMAKE_ON=	CONFIG+=libarchive
ARCHIVE_LIB_DEPENDS_OFF=libunarr.so:archivers/unarr

OPENGL_USES=		gl
OPENGL_USE=		GL=opengl
OPENGL_QMAKE_OFF=	CONFIG+=no_opengl

POPPLER_LIB_DEPENDS=	libpoppler-qt6.so:graphics/poppler-qt6
POPPLER_QMAKE_OFF=	CONFIG+=no_pdf

post-install:
.for l in YACReader YACReaderLibrary YACReaderLibraryServer
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${l}
.endfor

.include <bsd.port.mk>
