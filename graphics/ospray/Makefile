PORTNAME=	ospray
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
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

USES=		cmake:testing gl pkgconfig readline qt:5
USE_GITHUB=	yes
USE_GL=		gl glu
USE_QT=		core gui opengl qmake_build
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

CMAKE_OFF=	OSPRAY_APPS_TESTING
CMAKE_TESTING_ON=	OSPRAY_APPS_TESTING

post-patch: # replace alloca.h includes
	@${FIND} ${WRKSRC} -name "*.c*" -a -exec ${GREP} "#include <alloca\\.h>" {} \; -a -exec ${REINPLACE_CMD} -e "s|#include <alloca\\.h>|#include <stdlib.h>|" {} \; > /dev/null

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc/OSPRay

.include <bsd.port.mk>
