PORTNAME=	materialx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.39.4
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	MaterialX is an open standard for the exchange of rich material
WWW=		http://www.materialx.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libglvnd>0:graphics/libglvnd \
		openimageio>0:graphics/openimageio \
		openshadinglanguage>0:graphics/openshadinglanguage
LIB_DEPENDS=	libImath.so:math/Imath \
		libOpenImageIO.so:graphics/openimageio \
		libOpenImageIO_Util.so:graphics/openimageio

USES=		cmake gl localbase python:3.9+ xorg
USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation
GH_PROJECT=	MaterialX
GH_TUPLE=	mitsuba-renderer:nanogui:6452dd6:nanogui/source/MaterialXView/NanoGUI \
		ocornut:imgui:9aae45e:imgui/source/MaterialXGraphEditor/External/ImGui \
		thedmd:imgui-node-editor:2f99b2d:nodeeditor/source/MaterialXGraphEditor/External/ImGuiNodeEditor \
		wjakob:glfw:e130e55:glfw/source/MaterialXView/NanoGUI/ext/glfw \
		wjakob:nanobind:e504eeb:nanobind/source/MaterialXView/NanoGUI/ext/nanobind \
		wjakob:nanovg:bf2320d:nanovg/source/MaterialXView/NanoGUI/ext/nanovg \
		wjakob:nanovg_metal:075b04f:nanovgmetal/source/MaterialXView/NanoGUI/ext/nanovg_metal

USE_GL=		opengl
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xt

CMAKE_ARGS=	-DCMAKE_INSTALL_PREFIX=${STAGEDIR}${PREFIX}
CMAKE_ON=	MATERIALX_BUILD_GRAPH_EDITOR MATERIALX_BUILD_OIIO \
		MATERIALX_BUILD_PYTHON MATERIALX_BUILD_SHARED_LIBS \
		MATERIALX_BUILD_TESTS MATERIALX_BUILD_VIEWER \
		MATERIALX_INSTALL_PYTHON=${STAGEDIR}${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/MaterialXGraphEditor ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/MaterialXView ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/*.so* ${STAGEDIR}${PREFIX}/lib/
	${MKDIR} ${STAGEDIR}${DATADIR}/${PORTNAME}
	(cd ${WRKSRC}/resources  && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${PORTNAME})
	(cd ${WRKSRC}/source && ${COPYTREE_SHARE} .  ${STAGEDIR}${PREFIX}/include/${PORTNAME} "-name *.h")

do-test:
	cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
