# Created by: cartola (Carlos E. G. Carvalho)
# $FreeBSD$

PORTNAME=	vigra
DISTVERSION=	1.11.0
PORTREVISION=	4
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VIGRA stands for "Vision with Generic Algorithms"

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=     ukoethe
GH_TAGNAME=     e6c21f3

USES=		cmake
CMAKE_ARGS=	-DDEPENDENCY_SEARCH_PREFIX:PATH=${LOCALBASE} \
		-DDOCINSTALL:PATH=${DOCSDIR_REL}

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		HDF5 OPENEXR NUMPY DOCS
OPTIONS_DEFAULT=	HDF5 OPENEXR
NUMPY_DESC=		NumPy mathematical computing (USE Fortran/GCC47+)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHDF5}
CMAKE_ARGS+=	-DWITH_HDF5=1
LIB_DEPENDS+=	libhdf5.so:science/hdf5
.else
CMAKE_ARGS+=	-DWITH_HDF5=0
.endif

.if ${PORT_OPTIONS:MOPENEXR}
CMAKE_ARGS+=	-DWITH_OPENEXR=1
LIB_DEPENDS+=	libIlmImf.so:graphics/OpenEXR
.else
CMAKE_ARGS+=	-DWITH_OPENEXR=0
.endif

.if ${PORT_OPTIONS:MNUMPY}
# Should ignore Python3 since commit f51b0b5
#CONFLICTS_BUILD=	python3*
CMAKE_ARGS+=	-DWITH_VIGRANUMPY=1
USES+=		compiler:gcc-c++11-lib python:2
BUILD_DEPENDS+=	nosetests:devel/py-nose
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/numpy/core/numeric.py:math/py-numpy
#BUILD_DEPENDS+=	sphinx-build:textproc/py-sphinx
LIB_DEPENDS+=	libboost_python.so:devel/boost-python-libs
RUN_DEPENDS:=	${BUILD_DEPENDS}
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DWITH_VIGRANUMPY=0
PLIST_SUB+=	PYTHON="@comment "
.endif

# Vigra's CMakeLists.txt does not support disabling those so we hook them
# as dependencies here unconditionally (without OPTIONS=) even though if
# they are not present then Vigra/CMake will do without them (they are not
# mandatory).
#
# Notice that if you define e.g. WITHOUT_VIGRA_TIFF and graphics/tiff is
# installed on your system, then the lib will be picked up by Vigra, the
# dependency will not be recorded by the ports system and later deletion
# of graphics/tiff will break Vigra. Only define WITHOUT_VIGRA_TIFF if you
# do not have graphics/tiff installed and do not want TIFF support in Vigra.

.if !defined(WITHOUT_VIGRA_TIFF)
LIB_DEPENDS+=	libtiff.so:graphics/tiff
.endif

.if !defined(WITHOUT_VIGRA_JPEG)
USES+=		jpeg
.endif

.if !defined(WITHOUT_VIGRA_PNG)
LIB_DEPENDS+=	libpng.so:graphics/png
.endif

.if !defined(WITHOUT_VIGRA_FFTW)
LIB_DEPENDS+=	libfftw3.so:math/fftw3
LIB_DEPENDS+=	libfftw3f.so:math/fftw3-float
.endif

pre-everything::
.if ${PORT_OPTIONS:MNUMPY}
	@${ECHO} ""
	@${ECHO} "* BEWARE!"
	@${ECHO} "* Using py-NumPY implies Fortran and GCC 4.7+ as hard dependencies"
	@${ECHO} "* and require all ports, depending on vigra, to set USE_GCC=yes"
	@${ECHO} ""
.endif

post-patch:
# FIXME: This is ugly
	@${RM} ${WRKSRC}/include/vigra/*.orig

.include <bsd.port.mk>
