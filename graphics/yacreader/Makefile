PORTNAME=	yacreader
DISTVERSION=	9.14.2
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another comic reader
WWW=		https://www.yacreader.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

FLAVORS=	qt6 qt5

USES=		compiler:c++11-lib desktop-file-utils pkgconfig qmake qt:6
USE_GITHUB=	yes
USE_QT=		5compat base declarative multimedia svg tools:build

.if ${FLAVOR:U} == qt5
PKGNAMESUFFIX=	-${FLAVOR}
USES:=		${USES:S/qt:6/qt:5/}
USE_QT=		qmake:build buildtools:build core concurrent:build declarative \
		gui linguisttools:build multimedia network quickcontrols2 \
		sql sql-sqlite3:run svg testlib:build widgets
CONFLICTS_INSTALL=	${PORTNAME}
.else
CONFLICTS_INSTALL=	${PORTNAME}-qt5
.endif

OPTIONS_DEFINE=	ARCHIVE OPENGL POPPLER
OPTIONS_DEFAULT=OPENGL POPPLER

ARCHIVE_DESC=		libarchive instead of unarr for reading compressed formats
ARCHIVE_USES=		libarchive
ARCHIVE_QMAKE_ON=	CONFIG+=libarchive
ARCHIVE_LIB_DEPENDS_OFF=libunarr.so:archivers/unarr

OPENGL_USES=		gl
OPENGL_USE=		GL=gl
OPENGL_QMAKE_OFF=	CONFIG+=no_opengl

POPPLER_LIB_DEPENDS=	libpoppler-${FLAVOR}.so:graphics/poppler-${FLAVOR}
POPPLER_QMAKE_OFF=	CONFIG+=no_pdf

.include <bsd.port.mk>
