# $FreeBSD$

PORTNAME=	FreeCAD
DISTVERSION=	0.18.4
# use these for bugfixes/snapshots
# DISTVERSION=	0.18-16093 # git rev-list --count
# DISTVERSIONSUFFIX=	-g690774c0e
CATEGORIES=	cad

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	General purpose 3D CAD modeller

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyside2-tools>0:devel/pyside2-tools@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:math/py-matplotlib@${PY_FLAVOR} \
		swig3.0:devel/swig30
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		${PY_BOOST} \
		libpyside2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/pyside2@${PY_FLAVOR} \
		libCoin.so:graphics/Coin \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libvtkFiltersTexture-6.2.so:math/vtk6 \
		libTKernel.so:cad/opencascade \
		libxerces-c.so:textproc/xerces-c3 \
		libboost_thread.so:devel/boost-libs \
		libarea.so:devel/libarea \
		libmed.so:french/med \
		libshiboken2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/shiboken2@${PY_FLAVOR} \
		libhdf5.so:science/hdf5
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pivy-devel>0:graphics/py-pivy-devel@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:math/py-matplotlib@${PY_FLAVOR}

USES=		dos2unix compiler:c++11-lib cmake gl eigen:3 fortran jpeg \
		localbase:ldflags pkgconfig python:3.6 localbase qt:5 xorg
USE_GITHUB=	yes
USE_XORG=	ice sm x11 xext xt
USE_GL=		gl glu
USE_QT=		buildtools qmake_build core gui network opengl svg xml webkit widgets printsupport concurrent
USE_LDCONFIG=	yes

DOS2UNIX_GLOB=	*.txt *.h *.cpp *.py *.qss *.csv *.pov *.stp *.ui *.wrl *.WRL

# To be removed when french/med will be built against science/hdf5
LIB_DEPENDS+=	libhdf5-18.so:science/hdf5-18
CMAKE_ARGS+=	-DOCC_INCLUDE_DIR="${LOCALBASE}/include/OpenCASCADE" \
		-DHDF5_FOUND="TRUE" -DHDF5_VERSION="1.8.17"		\
		-DHDF5_INCLUDE_DIRS="${LOCALBASE}/include/hdf5-18"	\
		-DCMAKE_CXX_FLAGS="-I${LOCALBASE}/include/hdf5-18"	\
		-DCMAKE_C_FLAGS="-I${LOCALBASE}/include/hdf5-18"	\
		-DHDF5_LIBRARIES="-lhdf5-18" -DBUILD_QT5="ON" \
		-DPYTHON_LIBRARY="${PYTHONBASE}/lib/libpython${PYTHON_VER}${PYTHON_ABIVER}.so" \
		-DPYTHON_INCLUDE_DIR="${PYTHON_INCLUDEDIR}" \
		-DPYTHON_PACKAGES_PATH="${PYTHON_SITELIBDIR}" \
		-DPYTHON_EXECUTABLE="${PYTHON_CMD}" \
		-DBUILD_ASSEMBLY="OFF" -DBUILD_FLAT_MESH="ON"
CFLAGS+=	-I${LOCALBASE}/include/hdf5-18

CMAKE_INSTALL_PREFIX=	${PREFIX}/${PORTNAME}

OPTIONS_DEFINE=	COLLADA

COLLADA_DESC=		Install pycollada for Collada files import
COLLADA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycollada>0:graphics/py-pycollada@${PY_FLAVOR}

DESKTOP_ENTRIES=${PORTNAME} "" "${PREFIX}/FreeCAD/data/freecad.svg" \
		${PORTNAME} "Graphics;Engineering;" false

post-patch:
	@${REINPLACE_CMD} -e '/sed/s,-i,& \\"\\",' \
		${WRKSRC}/cMake/FindPySide*Tools.cmake
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		${WRKSRC}/src/Gui/CMakeLists.txt
	@${REINPLACE_CMD} -e '/self\.rev/s/Unknown/${DISTVERSION:C/.*-//}/' \
		${WRKSRC}/src/Tools/SubWCRev.py

pre-configure:
	# To be removed when french/med will be built against science/hdf5
	@${REINPLACE_CMD} -e 's|find_package(HDF5 REQUIRED)|#find_package(HDF5 REQUIRED)|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|<hdf5.h>|<hdf5-18/hdf5.h>|'	\
		${WRKSRC}/src/3rdParty/salomesmesh/inc/MED_Common.hxx

post-install:
	${LN} -s ../${PORTNAME}/bin/FreeCAD ${STAGEDIR}${LOCALBASE}/bin/FreeCAD
	${LN} -s ../${PORTNAME}/bin/FreeCADCmd ${STAGEDIR}${LOCALBASE}/bin/FreeCADCmd

.include <bsd.port.mk>
