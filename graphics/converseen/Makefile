# $FreeBSD$

PORTNAME=	converseen
PORTVERSION=	0.9.6.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Converseen/Converseen%20${PORTVERSION:R:R}/

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Easy to use graphics conversion utility

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick

USES=		cmake tar:bzip2 compiler:c++11-lang
USE_QT5=	core network gui linguisttools_build qmake_build \
		buildtools_build widgets
post-patch:
	@${REINPLACE_CMD} -e '/^ appdata.path =/s|/usr/share|$$$${SHARE_DIR}|' \
		${WRKSRC}/converseen.pro
	@${REINPLACE_CMD} -e '/^install(FILES converseen.appdata.xml/s|/usr|$${CMAKE_INSTALL_PREFIX}|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/converseen

.include <bsd.port.mk>
