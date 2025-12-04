PORTNAME=	FreeCAD
DISTVERSION=	r${GIT_SRC_DATE}
#PORTREVISION=	1
CATEGORIES=	cad
PKGNAMESUFFIX=  -devel

MAINTAINER=	mr@FreeBSD.org
COMMENT=	General purpose 3D CAD modeller
WWW=		https://www.freecadweb.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=      freecad # bin/FreeCAD

BUILD_DEPENDS=	doxygen:devel/doxygen \
		pybind11-config:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6-tools>0:devel/pyside6-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pivy>0:graphics/py-pivy@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:math/py-matplotlib@${PY_FLAVOR} \
		swig:devel/swig

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libyaml-cpp.so:devel/yaml-cpp \
		libfreetype.so:print/freetype2 \
		libtbb.so:devel/onetbb \
		${PY_BOOST} \
		libpyside6.abi3.so:devel/pyside6 \
		libCoin.so:graphics/Coin \
		libfmt.so:devel/libfmt \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libvtksys-${VTK_VER}.so:math/vtk${VTK_VER:R} \
		libTKernel.so:cad/opencascade \
		libxerces-c.so:textproc/xerces-c3 \
		libboost_thread.so:devel/boost-libs \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreeimage.so:graphics/freeimage \
		libavutil.so.58:multimedia/ffmpeg \
		libavformat.so.58:multimedia/ffmpeg4 \
		libmed.so:french/med \
		libshiboken6.abi3.so:devel/shiboken6@${PY_FLAVOR} \
		libhdf5.so:science/hdf5

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pivy>0:graphics/py-pivy@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:math/py-matplotlib@${PY_FLAVOR}

USES=		dos2unix compiler:c++20-lang cmake cpe gl eigen:3 fortran gmake jpeg \
		localbase:ldflags mpi:openmpi pkgconfig python localbase qt:6 xorg \
		desktop-file-utils shared-mime-info shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	FreeCAD:ondsel google:gtest microsoft:gsl FreeCAD:addonmgr
GH_PROJECT=	OndselSolver:ondsel googletest:gtest GSL:gsl AddonManager:addonmgr
GH_TAGNAME=	${GIT_SRC_HASH} ${GIT_ONDSEL_HASH}:ondsel ${GIT_GTEST_HASH}:gtest ${GIT_GSL_HASH}:gsl ${GIT_ADDONMGR_HASH}:addonmgr
GH_SUBDIR=	src/3rdParty/OndselSolver:ondsel tests/lib:gtest src/3rdParty/GSL:gsl src/Mod/AddonManager:addonmgr
USE_XORG=	ice sm x11 xext xt
USE_GL=		gl glu
USE_QT=		base svg tools
#USE_QT=		buildtools concurrent core declarative designer gui \
#		linguisttools location network opengl printsupport \
#		qmake:build svg webchannel widgets xml xmlpatterns
USE_LDCONFIG=	yes

CPE_VENDOR=	freecad_project

VTK_VER=	9.5

DOS2UNIX_GLOB=	*.txt *.h *.cpp *.py *.qss *.csv *.pov *.stp *.ui *.wrl *.WRL
SHEBANG_FILES=	src/Tools/freecad-thumbnailer.in

# our HDF5/CMake integration is messy, so workarounds are required below
CMAKE_ARGS+=	-DOCC_INCLUDE_DIR="${LOCALBASE}/include/OpenCASCADE" \
		-DOPENMPI_INCLUDE_DIRS="${LOCALBASE}/mpi/openmpi/include" \
		-DFREECAD_QT_VERSION=6 \
		-DBUILD_QT5="OFF" \
		-DBUILD_QT6="ON" \
		-DPYTHON_LIBRARY="${PYTHONBASE}/lib/libpython${PYTHON_VER}${PYTHON_ABIVER}.so" \
		-DPYTHON_INCLUDE_DIR="${PYTHON_INCLUDEDIR}" \
		-DPYTHON_PACKAGES_PATH="${PYTHON_SITELIBDIR}" \
		-DPYTHON_EXECUTABLE="${PYTHON_CMD}" \
		-DBUILD_ASSEMBLY="ON" \
		-DBUILD_DESIGNER_PLUGIN="ON" \
		-DBUILD_FLAT_MESH="ON" \
		-DBUILD_VR="OFF" \
		-DFREECAD_USE_EXTERNAL_FMT="ON" \
		-DFREECAD_CREATE_MAC_APP="OFF" \
		-DFREECAD_FREECAD_LIBPACK_USE="OFF" \
		-DFREECAD_USE_EXTERNAL_KDL="OFF" \
		-DFREECAD_USE_EXTERNAL_SMESH="OFF" \
		-DFREECAD_USE_FREETYPE="ON" \
		-DFREECAD_USE_PYBIND11="ON" \
		-DFREECAD_USE_PCL="OFF" \
		-Dpybind11_DIR="${PYTHON_SITELIBDIR}/pybind11/share/cmake/pybind11" \
		-DHDF5_CFLAGS="-I${LOCALBASE}/include" \
		-DHDF5_FOUND=TRUE \
		-DHDF5_VERSION="1.12.2" \
		-DHDF5_INCLUDE_DIRS="${LOCALBASE}/include/hdf5" \
		-DHDF5_LIBRARIES="-L${LOCALBASE}/lib -lhdf5" \
		-DHDF5_LIBRARY_DIRS="${LOCALBASE}/lib" \
		-DPYSIDE2RCCBINARY="${RCC}" \
		-DPYSIDE2UICBINARY="${UIC}" \
		-DBUILD_ENABLE_CXX_STD=C++20


CMAKE_INSTALL_PREFIX=	${PREFIX}/${PORTNAME}
# Install XDG icons and files to the standard path
CMAKE_ARGS+=	-DXDG_DATADIR="${PREFIX}/share"

OPTIONS_DEFINE=	COLLADA SPNAV

COLLADA_DESC=		Install pycollada for Collada files import
COLLADA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycollada>0:graphics/py-pycollada@${PY_FLAVOR}
OPTIONS_DEFINE= COLLADA SPNAV
SPNAV_DESC=             Enable libspnav (SpaceMouse) support
SPNAV_CMAKE_BOOL=       FREECAD_SPNAV_SUPPORT
SPNAV_LIB_DEPENDS=      libspnav.so:misc/libspnav


.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB=	WEBENGINE=""
USE_QT+=	webengine
.else
CMAKE_ARGS+=	-DBUILD_WEB:BOOL=OFF
PLIST_SUB=	WEBENGINE="@comment "
.endif

.include "Makefile.git_rev"

pre-configure:
	@${REINPLACE_CMD} -e '/self\.rev/s/Unknown/${DISTVERSION:C/.*-//}/' \
		${WRKSRC}/src/Tools/SubWCRev.py
# Install XDG icons and files to the standard path
	@${REINPLACE_CMD} -e 's/CMAKE_INSTALL_DATAROOTDIR/XDG_DATADIR/g' \
		${WRKSRC}/src/XDGData/CMakeLists.txt \
		${WRKSRC}/src/Gui/CMakeLists.txt

post-install:
	${LN} -sf ../${PORTNAME}/bin/FreeCAD ${STAGEDIR}${LOCALBASE}/bin/FreeCAD
	${LN} -sf ../${PORTNAME}/bin/FreeCADCmd ${STAGEDIR}${LOCALBASE}/bin/FreeCADCmd
	# ${INSTALL_SCRIPT} ${WRKSRC}/src/Tools/freecad-thumbnailer \
	# 	${STAGEDIR}${PREFIX}/bin/freecad-thumbnailer

.include <bsd.port.mk>
