# $FreeBSD$

PORTNAME=	converseen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.8.0
CATEGORIES=	graphics

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Easy to use graphics conversion utility

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick6

USES=		cmake compiler:c++11-lang qt:5 tar:bzip2
USE_QT=		core gui network widgets \
		buildtools_build linguisttools_build qmake_build

USE_GITHUB=	yes
GH_PROJECT=	Converseen
GH_ACCOUNT=	Faster3ck

post-patch:
	@${REINPLACE_CMD} -e '/^install(FILES converseen.appdata.xml/s|/usr|$${CMAKE_INSTALL_PREFIX}|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/converseen

.include <bsd.port.mk>
