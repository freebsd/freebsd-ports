# $FreeBSD$

PORTNAME=	yacreader
DISTVERSION=	9.7.1
PORTREVISION=	6
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Yet another comic reader

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libunarr.so:archivers/unarr

USES=		compiler:c++11-lib desktop-file-utils pkgconfig qmake qt:5
USE_GITHUB=	yes
USE_QT=		qmake_build buildtools_build core concurrent_build declarative \
		gui multimedia network script sql sql-sqlite3_run widgets

OPTIONS_DEFINE=	OPENGL POPPLER
OPTIONS_DEFAULT=OPENGL POPPLER

OPENGL_USES=		gl
OPENGL_USE=		GL=gl QT=opengl
OPENGL_QMAKE_OFF=	CONFIG+=no_opengl

POPPLER_LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5
POPPLER_QMAKE_OFF=	CONFIG+=no_pdf

.include <bsd.port.mk>
