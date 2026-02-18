PORTNAME=	materialx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.39.4
PORTREVISION=	3
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
		libOpenColorIO.so:graphics/opencolorio \
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

CMAKE_ARGS=	-DCMAKE_INSTALL_PREFIX=${STAGEDIR}${PREFIX} \
		-DNANOGUI_NATIVE_FLAGS="" \
		-DMATERIALX_INSTALL_RESOURCES=${PREFIX}/share/MaterialX \
		-DMATERIALX_INSTALL_PYTHON=${PREFIX}${PYTHONPREFIX_SITELIBDIR}/MaterialX

CMAKE_ON=	MATERIALX_BUILD_GRAPH_EDITOR \
		MATERIALX_BUILD_OCIO \
		MATERIALX_BUILD_OIIO \
		MATERIALX_BUILD_PYTHON \
		MATERIALX_BUILD_SHARED_LIBS \
		MATERIALX_BUILD_TESTS \
		MATERIALX_BUILD_VIEWER
post-patch:
	${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/cmake/modules/MaterialXConfig.cmake.in

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/MaterialXGraphEditor \
		${WRKDIR}/.build/bin/MaterialXView ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/*.so* ${STAGEDIR}${PREFIX}/lib
	(cd ${WRKSRC}/resources && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/MaterialX)
	(cd ${WRKSRC}/source && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/include "-name *.h")
	${INSTALL_DATA} ${BUILD_WRKSRC}/source/MaterialXCore/Generated.h \
		${STAGEDIR}${PREFIX}/include/MaterialXCore
	${INSTALL_DATA} ${WRKSRC}/source/MaterialXRender/TextureBaker.inl \
		${STAGEDIR}${PREFIX}/include/MaterialXRender
	(cd ${WRKSRC}/python/Scripts && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/MaterialX/examples)
	(cd ${WRKSRC}/python/MaterialX && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/MaterialX)
	(cd ${WRKSRC}/libraries && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/MaterialX/stdlib "-name *.mtlx")
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/MaterialX
	${INSTALL_DATA} ${WRKDIR}/.build/cmake/*.cmake \
		${BUILD_WRKSRC}/CMakeFiles/Export/6ec30f313a190b6699aad53a4a5af714/MaterialXTargets.cmake \
		${STAGEDIR}${PREFIX}/lib/cmake/MaterialX

do-test:
	cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
