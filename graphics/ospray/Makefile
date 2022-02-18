PORTNAME=	ospray
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Ray tracing based rendering engine for high-fidelity visualization

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	ispc:devel/ispc
LIB_DEPENDS=	libbenchmark.so:devel/benchmark \
		libembree3.so:graphics/embree \
		libglfw.so:graphics/glfw \
		libopenvkl.so:graphics/openvkl \
		librkcommon.so:devel/rkcommon \
		libtbb.so:devel/onetbb

USES=		cmake:testing compiler:c++11-lang gl pkgconfig readline qt:5
USE_GITHUB=	yes
USE_GL=		gl glu
USE_QT=		core gui opengl qmake_build
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

CMAKE_OFF=	OSPRAY_ENABLE_APPS_TESTING
CMAKE_TESTING_ON=	OSPRAY_ENABLE_APPS_TESTING

OPTIONS_DEFINE=		APPS
OPTIONS_DEFAULT=	APPS
OPTIONS_SUB=		yes

APPS_DESC=		Build apps
APPS_CMAKE_BOOL=	OSPRAY_ENABLE_APPS

post-patch: # replace alloca.h includes
	@${FIND} ${WRKSRC} -name "*.c*" -a -exec ${GREP} "#include <alloca\\.h>" {} \; -a -exec ${REINPLACE_CMD} -e "s|#include <alloca\\.h>|#include <stdlib.h>|" {} \; > /dev/null

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc/OSPRay

.include <bsd.port.mk>
