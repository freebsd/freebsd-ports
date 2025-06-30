PORTNAME=	ifcopenshell
PORTVERSION=	0.7.0.231127
PORTREVISION=	4
DISTVERSIONPREFIX=	v
CATEGORIES=	cad

PATCH_SITES=	https://github.com/IfcOpenShell/IfcOpenShell/commit/
PATCHFILES=	589b98053e62ee14b6817e7d2b9f5b6b527310b7.patch:-p1 \
		1fe168d331123920eeb9a96e542fcc1453de57fe.patch:-p1 \
		0f87bd8206a50d186621c2511d2e907bcf438968.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source IFC library and geometry engine
WWW=		https://ifcopenshell.org/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	${LOCALBASE}/include/CGAL/Cartesian.h:math/cgal \
		${LOCALBASE}/include/nlohmann/json.hpp:devel/nlohmann-json \
		${LOCALBASE}/include/svgpp/svgpp.hpp:graphics/svgpp
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libgmp.so:math/gmp libmpfr.so:math/mpfr \
		libTKernel.so:cad/opencascade740

USES=		cmake compiler:c++11-lang eigen:3 gnome
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	IfcOpenShell
GH_PROJECT=	IfcOpenShell svgfill:sf
GH_TAGNAME=	4d2aa7a:sf
GH_SUBDIR=	src/svgfill:sf

PORTSCOUT=	limit:^[0-9\.v]+$$

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_CMAKE_BOOL=	BUILD_IFCPYTHON
PYTHON_USES=		python
PYTHON_BUILD_DEPENDS=	swig>=3.0.0:devel/swig

CMAKE_SOURCE_PATH=	${WRKSRC}/cmake

CMAKE_OFF=	COLLADA_SUPPORT HDF5_SUPPORT
CMAKE_ON=	BUILD_SHARED_LIBS GLTF_SUPPORT
CMAKE_ARGS=	-DJSON_INCLUDE_DIR:PATH=${LOCALBASE}/include \
		-DOCC_INCLUDE_DIR:PATH=${LOCALBASE}/include/OpenCASCADE \
		-DGMP_LIBRARY_DIR:PATH=${LOCALBASE}/lib \
		-DMPFR_LIBRARY_DIR:PATH=${LOCALBASE}/lib

.include <bsd.port.mk>
