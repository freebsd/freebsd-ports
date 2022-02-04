PORTNAME=	ifcopenshell
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	cad

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Open source IFC library and geometry engine

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libTKernel.so:cad/opencascade740

USES=		cmake compiler:c++11-lang eigen:3 gnome
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_PROJECT=	IfcOpenShell
GH_TAGNAME=	7c61c7d200ff

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_CMAKE_BOOL=	BUILD_IFCPYTHON
PYTHON_USES=		python:3.6+
PYTHON_BUILD_DEPENDS=	swig>=3.0.0:devel/swig

CMAKE_SOURCE_PATH=	${WRKSRC}/cmake

CMAKE_OFF=	COLLADA_SUPPORT
CMAKE_ON=	BUILD_SHARED_LIBS \
		ENABLE_BUILD_OPTIMIZATIONS \
		GLTF_SUPPORT
CMAKE_ARGS=	-Djson_hpp=${LOCALBASE}/include/nlohmann \
		-DOCC_INCLUDE_DIR=${LOCALBASE}/include/OpenCASCADE \
		-DOCC_LIBRARY_DIR=${LOCALBASE}/lib

.include <bsd.port.mk>
