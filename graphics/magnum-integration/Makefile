PORTNAME=	magnum-integration
DISTVERSIONPREFIX=	v
DISTVERSION=	2020.06-264
PORTREVISION=	4
DISTVERSIONSUFFIX=	-g50ac4db
CATEGORIES=	graphics

BROKEN=		work/magnum-integration-2020.06-264-g50ac4db/src/Magnum/ImGuiIntegration/Context.cpp:322:23: error: no member named 'TextureId' in 'ImDrawCmd', "pcmd->TextureId"

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Magnum Graphics: Integration libraries
WWW=		https://magnum.graphics/ \
		https://github.com/mosra/magnum-integration

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glm>0:math/glm
LIB_DEPENDS=	libassimp.so:multimedia/assimp \
		libLinearMath.so:devel/bullet \
		libccd.so:math/libccd \
		libCorradePluginManager.so:devel/corrade \
		libdart.so:misc/dartsim \
		libfcl.so:math/fcl \
		libglfw.so:graphics/glfw \
		libfmt.so:devel/libfmt \
		libimgui.so:x11-toolkits/imgui \
		libMagnum.so:graphics/magnum \
		liboctomap.so:math/octomap

USES=		cmake compiler:c++14-lang gl
USE_GL=		opengl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mosra
GH_TUPLE=	mosra:toolchains:2243706:t/toolchains

CMAKE_ARGS=	-DLIB_SUFFIX:STRING=""

CMAKE_ON=	MAGNUM_WITH_BULLET \
		MAGNUM_WITH_EIGEN \
		MAGNUM_WITH_GLM \
		MAGNUM_WITH_DART \
		MAGNUM_WITH_IMGUI

.include <bsd.port.mk>
