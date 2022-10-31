PORTNAME=	yacreader
DISTVERSION=	9.10.0
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	a35cb979e4d3.patch:-p1 # https://github.com/YACReader/yacreader/pull/350

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Yet another comic reader
WWW=		https://www.yacreader.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libunarr.so:archivers/unarr

USES=		compiler:c++11-lib desktop-file-utils pkgconfig qmake qt:5
USE_GITHUB=	yes
USE_QT=		qmake:build buildtools:build core concurrent:build declarative \
		gui linguisttools:build multimedia network quickcontrols2 \
		sql sql-sqlite3:run svg testlib:build widgets

OPTIONS_DEFINE=	OPENGL POPPLER
OPTIONS_DEFAULT=OPENGL POPPLER

OPENGL_USES=		gl
OPENGL_USE=		GL=gl
OPENGL_QMAKE_OFF=	CONFIG+=no_opengl

POPPLER_LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5
POPPLER_QMAKE_OFF=	CONFIG+=no_pdf

.include <bsd.port.mk>
