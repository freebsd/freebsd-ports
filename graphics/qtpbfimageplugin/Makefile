PORTNAME=	qtpbfimageplugin
PORTVERSION=	2.1
PORTREVISION=	10
CATEGORIES=	graphics

MAINTAINER=	sikmir@gmail.com
COMMENT=	Qt image plugin for displaying Mapbox vector tiles
WWW=		https://github.com/tumic0/QtPBFImagePlugin

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf-lite.so:devel/protobuf

USES=		compiler:c++17-lang gl qmake qt:5
USE_QT=		core gui buildtools:build
USE_GL=		gl
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

USE_GITHUB=	yes
GH_ACCOUNT=	tumic0
GH_PROJECT=	QtPBFImagePlugin

USE_CXXSTD=	c++17

PLIST_FILES=	${QT_PLUGINDIR}/imageformats/libpbf.so

.include <bsd.port.mk>
