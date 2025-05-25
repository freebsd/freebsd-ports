PORTNAME=	gdalcpp
PORTVERSION=	1.3.0
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++11 GDAL wrapper
WWW=		https://github.com/joto/gdalcpp

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	gdal>=0:graphics/gdal

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/gdalcpp.hpp

USE_GITHUB=	yes
GH_ACCOUNT=	joto
GH_TAGNAME=	7e23085

do-install:
	${INSTALL_DATA} ${WRKSRC}/gdalcpp.hpp ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
