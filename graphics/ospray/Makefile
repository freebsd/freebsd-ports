PORTNAME=	ospray
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Ray tracing based rendering engine for high-fidelity visualization
WWW=		https://www.ospray.org/ \
		https://github.com/RenderKit/ospray

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	ispc:devel/ispc
LIB_DEPENDS=	libbenchmark.so:devel/benchmark \
		libembree4.so:graphics/embree \
		libglfw.so:graphics/glfw \
		libopenvkl.so:graphics/openvkl \
		librkcommon.so:devel/rkcommon \
		libtbb.so:devel/onetbb

USES=		cmake:testing compiler:c++11-lang gl pkgconfig
USE_GITHUB=	yes
GH_TUPLE=	ocornut:imgui:cb16be3a3fc1f9cd146ae24d52b615f8a05fa93d:imgui/apps/common/external/imgui-src \
		nothings:stb:013ac3beddff3dbffafd5177e7972067cd2b5083:stb/apps/common/external/stb-src
USE_GL=		gl glu
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION} \
		CMAKE_BUILD_TYPE=release

CMAKE_OFF=	OSPRAY_ENABLE_APPS_TESTING
CMAKE_TESTING_ON=	OSPRAY_ENABLE_APPS_TESTING
CMAKE_ARGS=	-DFETCHCONTENT_SOURCE_DIR_IMGUI:PATH=${WRKSRC}/apps/common/external/imgui-src \
		-DFETCHCONTENT_SOURCE_DIR_STB:PATH=${WRKSRC}/apps/common/external/stb-src

OPTIONS_DEFINE=		APPS
OPTIONS_DEFAULT=	APPS
OPTIONS_SUB=		yes

APPS_DESC=		Build apps
APPS_CMAKE_BOOL=	OSPRAY_ENABLE_APPS

post-patch: # replace alloca.h includes, apply imgui patch
	@${FIND} ${WRKSRC} -name "*.c*" -a -exec ${GREP} "#include <alloca\\.h>" {} \; -a -exec ${REINPLACE_CMD} -e "s|#include <alloca\\.h>|#include <stdlib.h>|" {} \; > /dev/null
	${PATCH} -p1 -d ${WRKSRC}/apps/common/external/imgui-src < ${WRKSRC}/apps/common/external/imgui/imgui.patch

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc/OSPRay

do-test:
	@echo "===> Running built-in OSPRay tutorial render test..."
	@cd ${BUILD_WRKSRC} && ./ospTutorial
	@if [ -f ${BUILD_WRKSRC}/accumulatedFrame.ppm ]; then \
		echo "===> Test successful: Beautifully accumulated frame rendered."; \
	else \
		echo "===> Test failed: Output frame was not generated."; \
		exit 1; \
	fi

.include <bsd.port.mk>
