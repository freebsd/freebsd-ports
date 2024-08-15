PORTNAME=	libbgcode
DISTVERSION=	0.2.0
PORTREVISION=   1
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
GH_TAGNAME=	8ae75bd
GH_TUPLE=	atomicobject:heatshrink:v0.4.1:heatshrink

CMAKE_ON=	BUILD_SHARED_LIBS LibBGCode_BUILD_DEPS
CMAKE_OFF=	LibBGCode_BUILD_TESTS

PORTDATA=	*

.include <bsd.port.mk>
