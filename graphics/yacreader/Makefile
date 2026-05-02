PORTNAME=	yacreader
DISTVERSION=	10.0.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/YACReader/${PORTNAME}/releases/download/${DISTVERSION}/
EXTRACT_SUFX=	-src.tar.xz

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Yet another comic reader
WWW=		https://www.yacreader.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake:testing compiler:c++17-lang desktop-file-utils gl \
		localbase pkgconfig qt:6 tar:xz
USE_GL=		opengl
USE_QT=		5compat base declarative multimedia speech svg tools:build

CMAKE_OFF=	BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS

OPTIONS_DEFINE=	ARCHIVE POPPLER
OPTIONS_DEFAULT=POPPLER

ARCHIVE_DESC=		libarchive instead of unarr for reading compressed formats
ARCHIVE_LIB_DEPENDS_OFF=libunarr.so:archivers/unarr
ARCHIVE_USES=		libarchive
ARCHIVE_CMAKE_ON=	-DDECOMPRESSION_BACKEND=libarchive

POPPLER_LIB_DEPENDS=	libpoppler-qt6.so:graphics/poppler-qt6
POPPLER_CMAKE_OFF=	-DPDF_BACKEND=no_pdf

.include <bsd.port.mk>
