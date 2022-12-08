PORTNAME=	yacreader
DISTVERSION=	9.10.0
PORTREVISION=	3
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	a35cb979e4d3.patch:-p1 # https://github.com/YACReader/yacreader/pull/350
PATCHFILES+=	be85954b0c42.patch:-p1 # https://github.com/YACReader/yacreader/pull/356
PATCHFILES+=	0574f2d345c2.patch:-p1 # https://github.com/YACReader/yacreader/pull/356
PATCHFILES+=	d4f12ff066f1.patch:-p1 # https://github.com/YACReader/yacreader/pull/356
PATCHFILES+=	06d744e88bf7.patch:-p1 # https://github.com/YACReader/yacreader/pull/356

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Yet another comic reader
WWW=		https://www.yacreader.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

FLAVORS=	qt5 qt6

USES=		compiler:c++11-lib desktop-file-utils pkgconfig qmake qt:5
USE_GITHUB=	yes
USE_QT=		qmake:build buildtools:build core concurrent:build declarative \
		gui linguisttools:build multimedia network quickcontrols2 \
		sql sql-sqlite3:run svg testlib:build widgets

.if ${FLAVOR:U} == qt6
PKGNAMESUFFIX=	-${FLAVOR}
USES:=		${USES:S/qt:5/qt:6/}
USE_QT=		5compat base declarative multimedia svg tools:build
CONFLICTS_INSTALL=	${PORTNAME}
.else
CONFLICTS_INSTALL=	${PORTNAME}-qt6
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
