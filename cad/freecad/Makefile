PORTNAME=	FreeCAD
DISTVERSION=	1.0.2
CATEGORIES=	cad

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	General purpose 3D CAD modeller
WWW=		https://www.freecadweb.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	doxygen:devel/doxygen \
		pybind11-config:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6-tools>0:devel/pyside6-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pivy>0:graphics/py-pivy@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_INCLUDEDIR}/CXX/Config.hxx:devel/py-cxx \
		microsoft-gsl>0:devel/microsoft-gsl \
		googletest>0:devel/googletest \
		swig:devel/swig
# the ffmpeg4 dependency is inherited via cad/opencascade
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libyaml-cpp.so:devel/yaml-cpp \
		libfreetype.so:print/freetype2 \
		libtbb.so:devel/onetbb \
		${PY_BOOST} \
		libpyside6.abi3.so:devel/pyside6@${PY_FLAVOR} \
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
		libhdf5.so:science/hdf5 \
		libspnav.so:misc/libspnav

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pivy>0:graphics/py-pivy@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:math/py-matplotlib@${PY_FLAVOR}

USES=		dos2unix compiler:c++17-lang cmake cpe gl eigen:3 fortran gmake jpeg \
		localbase:ldflags mpi:openmpi pkgconfig python localbase qt:6 xorg \
		desktop-file-utils shared-mime-info shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	Ondsel-Development:ondselsolver
GH_PROJECT=	OndselSolver:ondselsolver
GH_TAGNAME=	91f70382beeb58b32432b5a82da3802e4c19199c:ondselsolver
GH_SUBDIR=	src/3rdParty/OndselSolver:ondselsolver
USE_XORG=	ice sm x11 xext xt
USE_GL=		gl glu
USE_QT=		base declarative location svg tools webchannel
USE_LDCONFIG=	yes

CPE_VENDOR=	freecad_project

DOS2UNIX_GLOB=	*.txt *.h *.cpp *.py *.qss *.csv *.pov *.stp *.ui *.wrl *.WRL
SHEBANG_FILES=	src/Tools/freecad-thumbnailer

# our HDF5/CMake integration is messy, so workarounds are required below
CMAKE_ARGS+=	-DOCC_INCLUDE_DIR="${LOCALBASE}/include/OpenCASCADE" \
		-DOPENMPI_INCLUDE_DIRS="${LOCALBASE}/mpi/openmpi/include" \
		-DFREECAD_QT_VERSION="6" \
		-DPYTHON_LIBRARY="${PYTHONBASE}/lib/libpython${PYTHON_VER}${PYTHON_ABIVER}.so" \
		-DPYTHON_INCLUDE_DIR="${PYTHON_INCLUDEDIR}" \
		-DPYTHON_PACKAGES_PATH="${PYTHON_SITELIBDIR}" \
		-DPYTHON_EXECUTABLE="${PYTHON_CMD}" \
		-DPYCXX_INCLUDE_DIR="${PYTHON_INCLUDEDIR}" \
		-DBUILD_ASSEMBLY="ON" \
		-DBUILD_DESIGNER_PLUGIN="ON" \
		-DBUILD_FLAT_MESH="ON" \
		-DBUILD_TEST="OFF" \
		-DENABLE_DEVELOPER_TESTS="OFF" \
		-DBUILD_VR="OFF" \
		-DFREECAD_LIBPACK_USE="OFF" \
		-DFREECAD_USE_EXTERNAL_FMT="ON" \
		-DFREECAD_CREATE_MAC_APP="OFF" \
		-DFREECAD_FREECAD_LIBPACK_USE="OFF" \
		-DFREECAD_USE_EXTERNAL_KDL="OFF" \
		-DFREECAD_USE_EXTERNAL_SMESH="OFF" \
		-DFREECAD_USE_FREETYPE="ON" \
		-DFREECAD_USE_PYBIND11="ON" \
		-DUSE_CUDA="OFF" \
		-DUSE_OPENCV="OFF" \
		-Dpybind11_DIR="${PYTHON_SITELIBDIR}/pybind11/share/cmake/pybind11" \
		-DHDF5_CFLAGS="-I${LOCALBASE}/include" \
		-DHDF5_FOUND=TRUE \
		-DHDF5_VERSION="1.12.2" \
		-DHDF5_INCLUDE_DIRS="${LOCALBASE}/include/hdf5" \
		-DHDF5_LIBRARIES="-L${LOCALBASE}/lib -lhdf5" \
		-DHDF5_LIBRARY_DIRS="${LOCALBASE}/lib" \
		-DBUILD_ENABLE_CXX_STD=C++17 \
		-DXDG_DATADIR="${PREFIX}/share"

CMAKE_INSTALL_PREFIX=	${PREFIX}/${PORTNAME}

CXXFLAGS+=	-DGetCellLinks=GetLinks # fix for vtk-9.5.0: equivalent of this patch: https://github.com/FreeCAD/FreeCAD/issues/21731#issuecomment-2934487147

OPTIONS_DEFINE=	COLLADA

COLLADA_DESC=		Install pycollada for Collada files import
COLLADA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycollada>0:graphics/py-pycollada@${PY_FLAVOR}

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB=	WEBENGINE=""
USE_QT+=	webengine
.else
CMAKE_ARGS+=	-DBUILD_WEB:BOOL=OFF
PLIST_SUB=	WEBENGINE="@comment "
.endif

pre-configure:
	@${REINPLACE_CMD} -e '/self\.rev/s/Unknown/${DISTVERSION:C/.*-//}/' \
		${WRKSRC}/src/Tools/SubWCRev.py
# Install XDG icons and files to the standard path
	@${REINPLACE_CMD} -e 's/CMAKE_INSTALL_DATAROOTDIR/XDG_DATADIR/g' \
		${WRKSRC}/src/XDGData/CMakeLists.txt \
		${WRKSRC}/src/Gui/CMakeLists.txt

post-install:
	${LN} -s ../${PORTNAME}/bin/FreeCAD ${STAGEDIR}${LOCALBASE}/bin/FreeCAD
	${LN} -s ../${PORTNAME}/bin/FreeCADCmd ${STAGEDIR}${LOCALBASE}/bin/FreeCADCmd
	${INSTALL_SCRIPT} ${WRKSRC}/src/Tools/freecad-thumbnailer \
		${STAGEDIR}${PREFIX}/bin/freecad-thumbnailer

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
