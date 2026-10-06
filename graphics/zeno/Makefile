PORTNAME=	zeno
DISTVERSION=	2024.10.1
PORTREVISION=	4
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
		libBulletCollision.so:devel/bullet \
		libcryptopp.so:security/cryptopp \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libOpenEXR.so:graphics/openexr \
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

USES=		blaslapack:netlib cmake compiler:c++17-lang eigen:3 localbase:ldflags pkgconfig qt:5
USE_LDCONFIG=	yes
USE_QT=		core gui network opengl svg widgets buildtools:build qmake:build
USE_SDL=	sdl2
USE_XORG=	xext

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	heavy use of SSE instructions in ZenoFX module

# bundled OpenNL (meshfix) relies on implicit function declarations
CFLAGS+=	-Wno-error=implicit-function-declaration

USE_GITHUB=	yes
GH_ACCOUNT=	zenustech
GH_TUPLE+=	zenustech:bullet3:aa4931408428cd72057e59627770fc027c5bb0be:bullet/projects/Rigid/bullet3 \
		zenustech:OpenSubdiv:a50680658f9732a41fea8e150310cfb9b147dc3c:opensubdiv/projects/MeshSubdiv/OpenSubdiv \
		zenustech:assimp:745fcc9ba0c79feb4edfc71f464d6d4c920ecc06:assimp/projects/FBX/assimp \
		zenustech:libigl:4c94cfef23974d945a6c0cf97660c327839df5d0:libigl/projects/cgmesh/libigl \
		libigl:tetgen:4f3bfba3997f20aa1f96cfaff604313a8c2c85b6:tetgen/projects/cgmesh/libigl/external/tetgen \
		libigl:libigl-predicates:488242fa2b1f98a9c5bd1441297fb4a99a6a9ae4:predicates/projects/cgmesh/libigl/external/predicates

CMAKE_ON=	ZENO_BUILD_EDITOR ZENO_BUILD_SHARED ZENO_IPC_USE_TCP \
		ZENO_MULTIPROCESS ZENO_NO_WARNING ZENO_USE_CCACHE \
		ZENO_WITH_ZenoFX \
		ZENO_WITH_Alembic ZENO_SYSTEM_ALEMBIC \
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
		ZENO_WITH_TOOL_HerculesTools \
		ZENO_WITH_cgmesh ZENO_WITH_FEM ZENO_WITH_Skinning \
		ZENO_WITH_DemBones ZENO_WITH_FBX \
		LIBIGL_SKIP_DOWNLOAD

# Bundled assimp, voro++, meshfix and tetgen are linked statically into
# libzeno.so so nothing extra has to be installed
CMAKE_OFF=	ZENO_BUILD_DESIGNER ZENO_BUILD_PLAYER ZENO_INSTALL_TARGET \
		ZENO_MARCH_NATIVE ZENO_OPTIX_PROC ZENO_USE_FAST_MATH \
		ZENO_WIN32_RC ZENO_WITH_CUDA \
		ZFX_ENABLE_CUDA \
		BUILD_SHARED_LIBS VORO_BUILD_SHARED_LIBS \
		ASSIMP_BUILD_ASSIMP_TOOLS ASSIMP_BUILD_TESTS
		#ZENO_WITH_FastFLIP ZENO_WITH_zenvdb # compile zenovdb
		#ZENO_WITH_Euler ZENO_WITH_zenvdb # compile zenvdb killed gcc
		#ZENO_WITH_SampleModel # error: '_pgmptr' was not declared in this scope

# Skinning needs cgmesh (libigl) and FEM (LBFGSpp headers).
# FBX uses the bundled assimp fork; the prebuilt DemBones binaries from the
# dem-bones-bin submodule are Linux/Windows only, so ExportFBX looks for
# DemBones in ${PREFIX}/bin instead.
# SampleModel and zenvdb need submodules which are not fetched (openvdb), add
# them to GH_TUPLE when enabling those.
# ZENO_BUILD_DESIGNER - bug https://github.com/zenustech/zeno/issues/1907

PLIST_FILES=	bin/autotest \
		bin/zenoedit \
		lib/libzeno.so

# Bundled bullet3 fork is used only for parts devel/bullet does not provide
# (BulletInverseDynamics *.hpp, BussIK, VHACD, URDFImporter), the rest comes
# from devel/bullet
BULLET_FORK=	${WRKSRC}/projects/Rigid/bullet3

post-extract:
	@cd ${BULLET_FORK} && ${RM} -r HACD src/Bullet3* src/BulletCollision \
		src/BulletDynamics src/BulletSoftBody src/LinearMath src/clew \
		src/*.cpp src/*.h

post-patch:
	@${FIND} ${BULLET_FORK}/src -name '*.[ch]*' -exec ${REINPLACE_CMD} -E \
		's@#include "(\.\./)+(LinearMath|BulletCollision|BulletDynamics|Bullet3Common|btBullet)@#include "\2@' {} +

pre-configure:
	@if ${GREP} -q BT_USE_DOUBLE_PRECISION ${LOCALBASE}/libdata/pkgconfig/bullet.pc; then \
		${ECHO_MSG} "===> ${PKGNAME} requires single precision devel/bullet, deinstall bullet-double first"; \
		${FALSE}; \
	fi
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/ui/zenoui/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/autotest ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/zenoedit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/bin/libzeno.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
