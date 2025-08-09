PORTNAME=	zeno
DISTVERSION=	2024.10.1
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	ZEn NOde system - a simulation & rendering engine in nodes
WWW=		https://zenustech.com/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	alembic>0:graphics/alembic \
		boost-libs>=1.85.0:devel/boost-libs \
		c-blosc2>0:archivers/c-blosc2 \
		openmpi>0:net/openmpi \
		cgal>=5.0.2:math/cgal \
		onetbb>0:devel/onetbb \
		opencv>0:graphics/opencv \
		sdl2>0:devel/sdl20 \
		qwt6-qt5>0:x11-toolkits/qwt6

LIB_DEPENDS=	libAlembic.so:graphics/alembic \
		libcryptopp.so:security/cryptopp \
		libImath.so:math/Imath \
		libtiff.so:graphics/tiff \
		libopencv_highgui.so:graphics/opencv \
		libopencv_stitching.so:graphics/opencv \
		libopencv_videoio.so:graphics/opencv \
		libopencv_imgcodecs.so:graphics/opencv \
		libopencv_xfeatures2d.so:graphics/opencv \
		libopencv_ml.so:graphics/opencv \
		libopencv_shape.so:graphics/opencv \
		libopencv_calib3d.so:graphics/opencv \
		libopencv_features2d.so:graphics/opencv \
		libopencv_imgproc.so:graphics/opencv \
		libopencv_flann.so:graphics/opencv \
		libopencv_core.so:graphics/opencv

USES=		cmake compiler:c++17-lang eigen:3 localbase:ldflags pkgconfig qt:5
USE_LDCONFIG=	yes
USE_QT=		core gui network opengl svg widgets buildtools:build qmake:build
USE_GCC=	yes
USE_SDL=	sdl2
USE_XORG=	xext

USE_GITHUB=	yes
GH_ACCOUNT=	zenustech
GH_TUPLE+=	zenustech:openvdb:74a95a74d91e0115be00d7b94391f5607e02d60f:openvdb/projects/zenvdb/openvdb \
		zenustech:assimp:745fcc9ba0c79feb4edfc71f464d6d4c920ecc06:assimp/projects/FBX/assimp \
		zenustech:dem-bones-bin:30a39493f0394dfedc5d72ea463405b8f07a446e:dem/projects/FBX/dem-bones-bin \
		zenustech:libigl:9af4b833cb37c0d4b77ca62b7502284b3a83a47e:libigl/projects/cgmesh/libigl \
		zenustech:bullet3:aa4931408428cd72057e59627770fc027c5bb0be:bullet/projects/Rigid/bullet3 \
		zenustech:OpenSubdiv:a50680658f9732a41fea8e150310cfb9b147dc3c:opensubdiv/projects/MeshSubdiv/OpenSubdiv

CMAKE_ON=	ZENO_BUILD_EDITOR ZENO_BUILD_SHARED ZENO_IPC_USE_TCP \
		ZENO_MULTIPROCESS ZENO_NO_WARNING ZENO_USE_CCACHE \
		ZENOFX_ENABLE_LBVH \
		ZENO_WITH_Rigid \
		ZENO_WITH_oldzenbase \
		ZENO_WITH_TreeSketch \
		ZENO_SYSTEM_OPENVDB \
		ZENO_WITH_Functional \
		ZENO_WITH_LSystem \
		ZENO_WITH_mesher \
		ZENO_WITH_CalcGeometryUV \
		ZENO_WITH_MeshSubdiv \
		ZENO_WITH_Audio \
		ZENO_WITH_PBD \
		ZENO_WITH_GUI \
		ZENO_WITH_ImgCV \
		ZENO_WITH_TOOL_FLIPtools \
		ZENO_WITH_TOOL_cgmeshTools \
		ZENO_WITH_TOOL_BulletTools \
		ZENO_WITH_TOOL_HerculesTools

CMAKE_OFF=	ZENO_BUILD_DESIGNER ZENO_BUILD_PLAYER ZENO_INSTALL_TARGET \
		ZENO_MARCH_NATIVE ZENO_OPTIX_PROC ZENO_USE_FAST_MATH \
		ZENO_WIN32_RC ZENO_WITH_CUDA \
		ZENO_WITH_ZenoFX  ZENOFX_ENABLE_OPENVDB \
		ZENO_WITH_Alembic ZENO_SYSTEM_ALEMBIC
		#ZENO_WITH_FastFLIP ZENO_WITH_zenvdb # compile zenovdb
		#ZENO_WITH_Euler ZENO_WITH_zenvdb # compile zenvdb killed gcc
		#ZENO_WITH_Skinning ZENO_WITH_cgmesh # git download project dependent skinning on cgmesh
		#ZENO_WITH_cgmesh ZENO_WITH_FEM # git download projects dependent cgmesh on FEM
		#ZENO_WITH_DemBones ZENO_WITH_FBX # harcoded folder and libs in CMakefile
		#ZENO_WITH_SampleModel # error: '_pgmptr' was not declared in this scope

# ZENO_BUILD_DESIGNER - bug https://github.com/zenustech/zeno/issues/1907

# fix on 14.1: "ld: error: undefined reference due to --no-allow-shlib-undefined:
LDFLAGS+=	-Wl,--allow-shlib-undefined -lomp

PLIST_FILES=	bin/autotest \
		bin/zenoedit \
		lib/libzeno.so

pre-configure:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/ui/zenoui/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/autotest ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/zenoedit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/bin/libzeno.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
