PORTNAME=	yacreader
DISTVERSION=	9.16.0
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/YACReader/${PORTNAME}/releases/download/${DISTVERSION}/
EXTRACT_SUFX=	-src.tar.xz

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
