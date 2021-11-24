PORTNAME=	openvkl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	graphics devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel Open Volume Kernel Library for graphics applications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	ispc:devel/ispc
LIB_DEPENDS=	libembree3.so:graphics/embree \
		libglfw.so:graphics/glfw \
		librkcommon.so:devel/rkcommon \
		libtbbmalloc.so:devel/onetbb

USES=		cmake:testing gl
USE_GITHUB=	yes
USE_GL=		gl
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

OPTIONS_DEFINE=		DOCS VDB
OPTIONS_DEFAULT=	VDB

VDB_DESC=		Build with OpenVDB
VDB_CMAKE_ON=		-DOpenVDB_ROOT=${LOCALBASE}
VDB_LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
			libopenvdb.so:misc/openvdb

PORTDOCS=	*

.include <bsd.port.mk>
