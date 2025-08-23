PORTNAME=	openvkl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
CATEGORIES=	graphics devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel Open Volume Kernel Library for graphics applications
WWW=		https://github.com/openvkl/openvkl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	https://github.com/openvkl/openvkl/issues/14

BUILD_DEPENDS=	ispc:devel/ispc
LIB_DEPENDS=	libembree4.so:graphics/embree \
		libglfw.so:graphics/glfw \
		librkcommon.so:devel/rkcommon \
		libtbbmalloc.so:devel/onetbb

USES=		cmake:testing compiler:c++11-lib gl
USE_GITHUB=	yes
USE_GL=		gl
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING BUILD_EXAMPLES
CMAKE_TESTING_ON=	BUILD_TESTING

OPTIONS_DEFINE=		DOCS VDB
OPTIONS_DEFAULT=	VDB

VDB_DESC=		Build with OpenVDB
VDB_CMAKE_ON=		-DOpenVDB_ROOT=${LOCALBASE}
VDB_LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
			libopenvdb.so:misc/openvdb

PORTDOCS=	*

.include <bsd.port.mk>
