PORTNAME=	magnum-examples
DISTVERSIONPREFIX=	v
DISTVERSION=	2020.06-265
DISTVERSIONSUFFIX=	-gb843f07a
PORTREVISION=	6
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Magnum Graphics: Examples
WWW=		https://magnum.graphics/ \
		https://github.com/mosra/magnum-examples

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libCorradeUtility.so:devel/corrade \
		libMagnum.so:graphics/magnum \
		libMagnumBulletIntegration.so:graphics/magnum-integration \
		libMagnumUi.so:graphics/magnum-extras \
		\
		libassimp.so:multimedia/assimp \
		libbox2d.so:misc/box2d \
		libBulletDynamics.so:devel/bullet \
		libccd.so:math/libccd \
		libconsole_bridge.so:devel/ros-console_bridge \
		libdart.so:misc/dartsim \
		libfcl.so:math/fcl \
		libfmt.so:devel/libfmt \
		libglfw.so:graphics/glfw \
		libimgui.so:x11-toolkits/imgui \
		liboctomap.so:math/octomap \
		libtinyxml2.so:textproc/tinyxml2 \
		liburdfdom_model.so:devel/ros-urdfdom \
		libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:c++14-lang gl sdl
USE_GL=		opengl
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	mosra
GH_TUPLE=	mosra:toolchains:2243706:t/toolchains

CMAKE_ON=	\
		MAGNUM_WITH_ARCBALL_EXAMPLE \
		MAGNUM_WITH_ANIMATED_GIF_EXAMPLE \
		MAGNUM_WITH_AREALIGHTS_EXAMPLE \
		MAGNUM_WITH_BOX2D_EXAMPLE \
		MAGNUM_WITH_BULLET_EXAMPLE \
		MAGNUM_WITH_CUBEMAP_EXAMPLE \
		MAGNUM_WITH_DART_EXAMPLE \
		MAGNUM_WITH_FLUIDSIMULATION2D_EXAMPLE \
		MAGNUM_WITH_FLUIDSIMULATION3D_EXAMPLE \
		MAGNUM_WITH_IMGUI_EXAMPLE \
		MAGNUM_WITH_MOUSEINTERACTION_EXAMPLE \
		MAGNUM_WITH_MOTIONBLUR_EXAMPLE \
		MAGNUM_WITH_OCTREE_EXAMPLE \
		MAGNUM_WITH_PICKING_EXAMPLE \
		MAGNUM_WITH_PRIMITIVES_EXAMPLE \
		MAGNUM_WITH_RAYTRACING_EXAMPLE \
		MAGNUM_WITH_SHADOWS_EXAMPLE \
		MAGNUM_WITH_TEXT_EXAMPLE \
		MAGNUM_WITH_TEXTUREDQUAD_EXAMPLE \
		MAGNUM_WITH_TEXTUREDTRIANGLE_VULKAN_EXAMPLE \
		MAGNUM_WITH_TRIANGLE_EXAMPLE \
 		MAGNUM_WITH_TRIANGLE_PLAIN_GLFW_EXAMPLE \
		MAGNUM_WITH_TRIANGLE_VULKAN_EXAMPLE \
		MAGNUM_WITH_VIEWER_EXAMPLE
#CMAKE_ON+=	MAGNUM_WITH_OVR_EXAMPLE # unclear if this is for Linux/BSD
#CMAKE_ON+=	MAGNUM_WITH_LEAPMOTION_EXAMPLE # needs the Leap library
#CMAKE_ON+=	MAGNUM_WITH_TRIANGLE_SOKOL_EXAMPLE # broken, see https://github.com/mosra/magnum-examples/issues/111

.include <bsd.port.mk>
