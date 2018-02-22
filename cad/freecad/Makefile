# $FreeBSD$

PORTNAME=	FreeCAD
DISTVERSION=	0.17.12018
PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose 3D CAD modeller

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	pyside-rcc:devel/pyside-tools \
		swig3.0:devel/swig30
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		${PY_BOOST} \
		libpyside-python2.7.so:devel/pyside@${PY_FLAVOR} \
		libCoin.so:graphics/Coin \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libvtkFiltersTexture-6.2.so:math/vtk6 \
		libTKernel.so:cad/opencascade \
		libSoQt.so:x11-toolkits/soqt \
		libxerces-c.so:textproc/xerces-c3 \
		libboost_thread.so:devel/boost-libs \
		libarea.so:devel/libarea \
		libmed.so:french/med \
		libshiboken-${PYTHON_VERSION}.so:devel/shiboken \
		libhdf5.so:science/hdf5
RUN_DEPENDS=	pivy>0:graphics/py-pivy@${PY_FLAVOR}

USES=		dos2unix compiler:c++11-lib cmake:outsource eigen:3 fortran jpeg \
		python:2.7 localbase
USE_XORG=	ice sm x11 xext xt
USE_GL=		gl glu
USE_QT4=	qmake_build corelib gui moc_build network opengl rcc_build \
		uic_build svg xml webkit
USE_LDCONFIG=	yes
DOS2UNIX_GLOB=	*.txt *.h *.cpp *.py *.qss *.csv *.pov *.stp *.ui *.wrl *.WRL
CMAKE_ARGS=	-DOCC_INCLUDE_DIR="${LOCALBASE}/include/OpenCASCADE"

# To be removed when french/med will be built against science/hdf5
LIB_DEPENDS+=	libhdf5-18.so:science/hdf5-18
CMAKE_ARGS+=	-DHDF5_FOUND="TRUE" -DHDF5_VERSION="1.8.17"		\
		-DHDF5_INCLUDE_DIRS="${LOCALBASE}/include/hdf5-18"	\
		-DCMAKE_CXX_FLAGS="-I${LOCALBASE}/include/hdf5-18"	\
		-DCMAKE_C_FLAGS="-I${LOCALBASE}/include/hdf5-18"	\
		-DHDF5_LIBRARIES="-lhdf5-18"
CFLAGS+=	-I${LOCALBASE}/include/hdf5-18

CMAKE_INSTALL_PREFIX=	${PREFIX}/${PORTNAME}

USE_GITHUB=	yes
GH_TAGNAME=	f27617e

OPTIONS_DEFINE=	COLLADA

COLLADA_DESC=		Install pycollada for Collada files import
COLLADA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycollada>0:graphics/py-pycollada@${PY_FLAVOR}

DESKTOP_ENTRIES=${PORTNAME} "" "${PREFIX}/FreeCAD/data/freecad.svg" \
		${PORTNAME} "Engineering;" false

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		${WRKSRC}/src/Gui/CMakeLists.txt

pre-configure:
	@${CP} ${FILESDIR}/version.h \
		${WRKSRC}/src/Build/Version.h
	# To be removed when french/med will be built against science/hdf5
	@${REINPLACE_CMD} -e 's|find_package(HDF5 REQUIRED)|#find_package(HDF5 REQUIRED)|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|<hdf5.h>|<hdf5-18/hdf5.h>|'	\
		${WRKSRC}/src/3rdParty/salomesmesh/inc/MED_Common.hxx

post-install:
	${LN} -s ../${PORTNAME}/bin/FreeCAD ${STAGEDIR}${LOCALBASE}/bin/FreeCAD
	${LN} -s ../${PORTNAME}/bin/FreeCADCmd ${STAGEDIR}${LOCALBASE}/bin/FreeCADCmd

.include <bsd.port.mk>
