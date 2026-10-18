PORTNAME=	zeno
DISTVERSION=	2024.10.1
PORTREVISION=	6
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	ZEn NOde system - a simulation & rendering engine in nodes
WWW=		https://zenustech.com/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>=1.85.0:devel/boost-libs \
		c-blosc2>0:archivers/c-blosc2 \
		onetbb>0:devel/onetbb \
		openmpi>0:net/openmpi \
		${_QWT_LIB}:x11-toolkits/qwt6@qt6

LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libboost_chrono.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libcryptopp.so:security/cryptopp \
		libminizip.so:archivers/minizip
RUN_DEPENDS=	${_QWT_LIB}:x11-toolkits/qwt6@qt6

USES=		cmake compiler:c++17-lang eigen:3 gl localbase:ldflags pkgconfig \
		qt:6
USE_GL=		gl opengl
USE_LDCONFIG=	yes
USE_QT=		base svg

USE_GITHUB=	yes
GH_ACCOUNT=	zenustech

# The bundled Qwt is a prebuilt static library for Qt 5, use the Qt 6 flavor
# of x11-toolkits/qwt6 instead.  Both flavors install libqwt.so, so depend on
# the Qt 6 one by path: LIB_DEPENDS would be satisfied by qwt6-qt5 as well.
_QWT_LIB=	${LOCALBASE}/${QT_LIBDIR_REL}/libqwt.so
CMAKE_ARGS=	-DQWT_INCLUDE_DIR:PATH=${LOCALBASE}/${QT_INCDIR_REL}/qwt6 \
		-DQWT_LIBRARY:FILEPATH=${_QWT_LIB}
CMAKE_ON=	ZENO_BUILD_EDITOR ZENO_BUILD_SHARED ZENO_IPC_USE_TCP \
		ZENO_MULTIPROCESS ZENO_NO_WARNING ZENO_USE_CCACHE \
		ZENO_SYSTEM_OPENVDB

# Bundled assimp, voro++, meshfix and tetgen are linked statically into
# libzeno.so so nothing extra has to be installed
CMAKE_OFF=	ZENO_BUILD_DESIGNER ZENO_BUILD_PLAYER ZENO_INSTALL_TARGET \
		ZENO_MARCH_NATIVE ZENO_OPTIX_PROC ZENO_USE_FAST_MATH \
		ZENO_WIN32_RC ZENO_WITH_CUDA \
		ZFX_ENABLE_CUDA \
		BUILD_SHARED_LIBS VORO_BUILD_SHARED_LIBS \
		ASSIMP_BUILD_ASSIMP_TOOLS ASSIMP_BUILD_TESTS

# Every extension below is a set of nodes compiled into libzeno.so, so these
# options only change what the editor offers - the package always installs the
# same files.  Extensions that stay off and why:
#   zenvdb, FastFLIP	# need the openvdb submodule, add it to GH_TUPLE first
#   Euler		# needs zenvdb, and compiling it killed gcc
#   SampleModel		# error: '_pgmptr' was not declared in this scope
#   CUDA, CuEulerian, CuLagrange, PyZpc, Nemo	# need CUDA
#   GLTF, USD, Python, Roads, Geometry, ...	# not tried on FreeBSD yet
# ZENO_BUILD_DESIGNER - bug https://github.com/zenustech/zeno/issues/1907
OPTIONS_DEFINE=	ALEMBIC AUDIO CALCUV CGMESH DEMBONES FBX FEM FUNCTIONAL \
		GUI IMGCV LSYSTEM MESHER MESHSUBDIV OLDZENBASE PBD RIGID \
		SKINNING TREESKETCH ZENOFX
OPTIONS_GROUP=	TOOLS
OPTIONS_GROUP_TOOLS=	BULLETTOOLS CGMESHTOOLS FLIPTOOLS HERCULESTOOLS
OPTIONS_DEFAULT=	ALEMBIC AUDIO CALCUV CGMESH DEMBONES FBX FEM \
			FUNCTIONAL GUI IMGCV LSYSTEM MESHER MESHSUBDIV \
			OLDZENBASE PBD RIGID SKINNING TREESKETCH ZENOFX \
			BULLETTOOLS CGMESHTOOLS FLIPTOOLS HERCULESTOOLS

ALEMBIC_DESC=		Alembic (.abc) import and export nodes
AUDIO_DESC=		Audio analysis nodes (bundled Aquila)
CALCUV_DESC=		UV unwrapping nodes (bundled xatlas)
CGMESH_DESC=		Computational geometry nodes (libigl, CGAL, voro++)
DEMBONES_DESC=		Skinning decomposition nodes (DemBones)
FBX_DESC=		FBX import and export nodes (bundled assimp)
FEM_DESC=		Finite element nodes, implies CGMESH
FUNCTIONAL_DESC=	Functional programming nodes
GUI_DESC=		Interactive viewport nodes (SDL2)
IMGCV_DESC=		Image processing nodes (OpenCV)
LSYSTEM_DESC=		L-system procedural growth nodes
MESHER_DESC=		Mesh generation nodes
MESHSUBDIV_DESC=	Subdivision surface nodes (bundled OpenSubdiv)
OLDZENBASE_DESC=	Legacy mesh and particle nodes
PBD_DESC=		Position based dynamics nodes
RIGID_DESC=		Rigid body nodes (Bullet)
SKINNING_DESC=		Mesh skinning nodes, implies CGMESH and FEM
TREESKETCH_DESC=	Tree sketching nodes
ZENOFX_DESC=		ZenoFX expression wrangler nodes
TOOLS_DESC=		Node graph presets
BULLETTOOLS_DESC=	Bullet presets, implies RIGID
CGMESHTOOLS_DESC=	Voronoi fracture presets, implies CGMESH
FLIPTOOLS_DESC=		FLIP fluid presets
HERCULESTOOLS_DESC=	Hercules presets

ALEMBIC_CMAKE_BOOL=	ZENO_WITH_Alembic ZENO_SYSTEM_ALEMBIC
ALEMBIC_BUILD_DEPENDS=	alembic>0:graphics/alembic
ALEMBIC_LIB_DEPENDS=	libAlembic.so:graphics/alembic \
			libImath.so:math/Imath \
			libOpenEXR.so:graphics/openexr \
			libpng16.so:graphics/png

AUDIO_CMAKE_BOOL=	ZENO_WITH_Audio

CALCUV_CMAKE_BOOL=	ZENO_WITH_CalcGeometryUV

# The bundled zenustech/libigl fork pulled in here (and with it FEM and
# SKINNING) dates from 2022 and asks for Eigen 3.3.7 in its own CMake; its
# diag() and slice_into() use Eigen::DynamicSparseMatrix, which Eigen 5 no
# longer ships.  The patches below swap that for Eigen::SparseMatrix, so the
# igl headers zeno uses compile against math/eigen3 as well as math/eigen5.
# eigen:3 stays for now: CGAL and the rest of the stack here are still built
# against Eigen 3.
CGMESH_CMAKE_BOOL=	ZENO_WITH_cgmesh LIBIGL_SKIP_DOWNLOAD
CGMESH_USES=		blaslapack:netlib
CGMESH_BUILD_DEPENDS=	cgal>=5.0.2:math/cgal
CGMESH_LIB_DEPENDS=	libgmp.so:math/gmp \
			libmpfr.so:math/mpfr
CGMESH_GH_TUPLE=	zenustech:libigl:4c94cfef23974d945a6c0cf97660c327839df5d0:libigl/projects/cgmesh/libigl \
			libigl:tetgen:4f3bfba3997f20aa1f96cfaff604313a8c2c85b6:tetgen/projects/cgmesh/libigl/external/tetgen \
			libigl:libigl-predicates:488242fa2b1f98a9c5bd1441297fb4a99a6a9ae4:predicates/projects/cgmesh/libigl/external/predicates
# The libigl fork only gets extracted when this option is on, so its patches
# have to be conditional too
CGMESH_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-libigl-diag \
			${PATCHDIR}/extra-patch-libigl-meshfix-jqsort \
			${PATCHDIR}/extra-patch-libigl-slice_into
# bundled OpenNL (meshfix) relies on implicit function declarations
CGMESH_CFLAGS=		-Wno-error=implicit-function-declaration

DEMBONES_CMAKE_BOOL=	ZENO_WITH_DemBones

# The prebuilt DemBones binaries from the dem-bones-bin submodule are
# Linux/Windows only, so ExportFBX looks for DemBones in ${PREFIX}/bin instead
FBX_CMAKE_BOOL=		ZENO_WITH_FBX
FBX_GH_TUPLE=		zenustech:assimp:745fcc9ba0c79feb4edfc71f464d6d4c920ecc06:assimp/projects/FBX/assimp

FEM_CMAKE_BOOL=		ZENO_WITH_FEM
FEM_IMPLIES=		CGMESH

FUNCTIONAL_CMAKE_BOOL=	ZENO_WITH_Functional

GUI_CMAKE_BOOL=		ZENO_WITH_GUI
GUI_USES=		sdl xorg
GUI_USE=		SDL=sdl2 XORG=xext

IMGCV_CMAKE_BOOL=	ZENO_WITH_ImgCV
IMGCV_BUILD_DEPENDS=	opencv>0:graphics/opencv
IMGCV_LIB_DEPENDS=	libopencv_calib3d.so:graphics/opencv \
			libopencv_core.so:graphics/opencv \
			libopencv_features2d.so:graphics/opencv \
			libopencv_flann.so:graphics/opencv \
			libopencv_highgui.so:graphics/opencv \
			libopencv_imgcodecs.so:graphics/opencv \
			libopencv_imgproc.so:graphics/opencv \
			libopencv_ml.so:graphics/opencv \
			libopencv_shape.so:graphics/opencv \
			libopencv_stitching.so:graphics/opencv \
			libopencv_videoio.so:graphics/opencv \
			libopencv_xfeatures2d.so:graphics/opencv \
			libtiff.so:graphics/tiff

LSYSTEM_CMAKE_BOOL=	ZENO_WITH_LSystem

MESHER_CMAKE_BOOL=	ZENO_WITH_mesher

MESHSUBDIV_CMAKE_BOOL=	ZENO_WITH_MeshSubdiv
MESHSUBDIV_GH_TUPLE=	zenustech:OpenSubdiv:a50680658f9732a41fea8e150310cfb9b147dc3c:opensubdiv/projects/MeshSubdiv/OpenSubdiv

OLDZENBASE_CMAKE_BOOL=	ZENO_WITH_oldzenbase

PBD_CMAKE_BOOL=		ZENO_WITH_PBD

# Bundled bullet3 fork is used only for parts devel/bullet does not provide
# (BulletInverseDynamics *.hpp, BussIK, VHACD, URDFImporter), the rest comes
# from devel/bullet
RIGID_CMAKE_BOOL=	ZENO_WITH_Rigid
RIGID_LIB_DEPENDS=	libBulletCollision.so:devel/bullet
RIGID_GH_TUPLE=		zenustech:bullet3:aa4931408428cd72057e59627770fc027c5bb0be:bullet/projects/Rigid/bullet3

SKINNING_CMAKE_BOOL=	ZENO_WITH_Skinning
# skinning_bbw.cpp includes LBFGSB.h, which only lands on the include path
# when FEM is built
SKINNING_IMPLIES=	CGMESH FEM

TREESKETCH_CMAKE_BOOL=	ZENO_WITH_TreeSketch

ZENOFX_CMAKE_BOOL=	ZENO_WITH_ZenoFX

BULLETTOOLS_CMAKE_BOOL=		ZENO_WITH_TOOL_BulletTools
BULLETTOOLS_IMPLIES=		RIGID
CGMESHTOOLS_CMAKE_BOOL=		ZENO_WITH_TOOL_cgmeshTools
CGMESHTOOLS_IMPLIES=		CGMESH
FLIPTOOLS_CMAKE_BOOL=		ZENO_WITH_TOOL_FLIPtools
HERCULESTOOLS_CMAKE_BOOL=	ZENO_WITH_TOOL_HerculesTools

DESKTOP_ENTRIES=	"ZENO" "Node based simulation and rendering engine" \
			"zeno" "zenoedit" "Graphics;3DGraphics;" false

ICON_SIZES=	64 128 256

PLIST_FILES=	bin/autotest \
		bin/zenoedit \
		lib/libzeno.so \
		${ICON_SIZES:@s@share/icons/hicolor/${s}x${s}/apps/zeno.png@}

BULLET_FORK=	${WRKSRC}/projects/Rigid/bullet3

post-extract-RIGID-on:
	@cd ${BULLET_FORK} && ${RM} -r HACD src/Bullet3* src/BulletCollision \
		src/BulletDynamics src/BulletSoftBody src/LinearMath src/clew \
		src/*.cpp src/*.h

BULLET_INCLUDE=	\#include "(\.\./)+(LinearMath|BulletCollision|BulletDynamics|Bullet3Common|btBullet)

post-patch-RIGID-on:
	@${FIND} ${BULLET_FORK}/src -name '*.[ch]*' -exec ${GREP} -lE '${BULLET_INCLUDE}' {} + | \
		${XARGS} ${REINPLACE_CMD} -E 's@${BULLET_INCLUDE}@#include "\2@'

pre-configure-RIGID-on:
	@if ${GREP} -q BT_USE_DOUBLE_PRECISION ${LOCALBASE}/libdata/pkgconfig/bullet.pc; then \
		${ECHO_MSG} "===> ${PKGNAME} requires single precision devel/bullet, deinstall bullet-double first"; \
		${FALSE}; \
	fi

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/autotest ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/zenoedit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/bin/libzeno.so ${STAGEDIR}${PREFIX}/lib
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/ui/zenoedit/res/icons/ZENO-logo${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/zeno.png
.endfor

.include <bsd.port.mk>
