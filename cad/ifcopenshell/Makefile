# $FreeBSD$

PORTNAME=	ifcopenshell
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
DISTVERSIONSUFFIX=	b0
PORTREVISION=	2
CATEGORIES=	cad

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Open source IFC library and geometry engine

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libTKernel.so:cad/opencascade

USES=		cmake compiler:c++11-lang eigen:3 gnome
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_PROJECT=	IfcOpenShell

CMAKE_SOURCE_PATH=	${WRKSRC}/cmake

CMAKE_OFF=	BUILD_IFCPYTHON \
		COLLADA_SUPPORT
CMAKE_ON=	BUILD_SHARED_LIBS \
		ENABLE_BUILD_OPTIMIZATIONS \
		GLTF_SUPPORT
CMAKE_ARGS=	-Djson_hpp=${LOCALBASE}/include/nlohmann \
		-DOCC_INCLUDE_DIR=${LOCALBASE}/include/OpenCASCADE \
		-DOCC_LIBRARY_DIR=${LOCALBASE}/lib

.include <bsd.port.mk>
