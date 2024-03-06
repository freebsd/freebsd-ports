PORTNAME=	libbgcode
DISTVERSION=	0.2.0
CATEGORIES=	cad

MAINTAINER=	teodorsigaev@gmail.com
COMMENT=	Prusa Block & Binary G-code reader/writer/converter
WWW=		https://github.com/prusa3d/libbgcode

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_nowide.so:devel/boost-libs

USES=	cmake

USE_GITHUB=	yes
GH_ACCOUNT=	prusa3d
GH_TAGNAME=	6f43cb004ef3d3bda37dde49f6235e24d2717629
GH_TUPLE=	atomicobject:heatshrink:v0.4.1:heatshrink

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON \
		-DLibBGCode_BUILD_DEPS=ON \
		-DLibBGCode_BUILD_TESTS=OFF

PORTDATA=	*

.include <bsd.port.mk>
