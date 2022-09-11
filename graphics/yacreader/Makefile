PORTNAME=	yacreader
DISTVERSION=	9.9.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Yet another comic reader
WWW=		https://www.yacreader.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libunarr.so:archivers/unarr

USES=		compiler:c++11-lib desktop-file-utils pkgconfig qmake qt:5
USE_GITHUB=	yes
USE_QT=		qmake:build buildtools:build core concurrent:build declarative \
		gui multimedia network quickcontrols2 sql sql-sqlite3:run svg \
		testlib:build widgets

OPTIONS_DEFINE=	OPENGL POPPLER
OPTIONS_DEFAULT=OPENGL POPPLER

OPENGL_USES=		gl
OPENGL_USE=		GL=gl
OPENGL_QMAKE_OFF=	CONFIG+=no_opengl

POPPLER_LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5
POPPLER_QMAKE_OFF=	CONFIG+=no_pdf

.include <bsd.port.mk>
