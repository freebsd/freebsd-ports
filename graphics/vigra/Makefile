# Created by: cartola (Carlos E. G. Carvalho)
# $FreeBSD$

PORTNAME=	vigra
PORTVERSION=	1.9.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://hci.iwr.uni-heidelberg.de/vigra/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	VIGRA stands for "Vision with Generic Algorithms"

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		cmake
CMAKE_ARGS=	-DDEPENDENCY_SEARCH_PREFIX:PATH=${LOCALBASE} \
		-DDOCINSTALL:PATH=${DOCSDIR_REL}

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		HDF5 OPENEXR NUMPY
OPTIONS_DEFAULT=	HDF5 OPENEXR
NUMPY_DESC=		NumPy mathematical computing (USE Fortran/GCC46+)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHDF5}
CMAKE_ARGS+=	-DWITH_HDF5=1
LIB_DEPENDS+=	hdf5.7:${PORTSDIR}/science/hdf5-18
.else
CMAKE_ARGS+=	-DWITH_HDF5=0
.endif

.if ${PORT_OPTIONS:MOPENEXR}
CMAKE_ARGS+=	-DWITH_OPENEXR=1
LIB_DEPENDS+=	IlmImf:${PORTSDIR}/graphics/OpenEXR
.else
CMAKE_ARGS+=	-DWITH_OPENEXR=0
.endif

.if ${PORT_OPTIONS:MNUMPY}
CONFLICTS_BUILD=	python3*
CMAKE_ARGS+=	-DWITH_VIGRANUMPY=1
USE_GCC=	yes
USE_FORTRAN=	yes
USE_PYTHON=	2.6-2.7
BUILD_DEPENDS+=	nosetests:${PORTSDIR}/devel/py-nose
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/numpy/core/numeric.py:${PORTSDIR}/math/py-numpy
#BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
LIB_DEPENDS=	boost_python:${PORTSDIR}/devel/boost-python-libs
RUN_DEPENDS:=	${BUILD_DEPENDS}
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DWITH_VIGRANUMPY=0
PLIST_SUB+=	PYTHON="@comment "
.endif

.include <bsd.port.pre.mk>

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
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
.endif

.if !defined(WITHOUT_VIGRA_JPEG)
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
.endif

.if !defined(WITHOUT_VIGRA_PNG)
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
.endif

.if !defined(WITHOUT_VIGRA_FFTW)
LIB_DEPENDS+=	fftw3:${PORTSDIR}/math/fftw3
LIB_DEPENDS+=	fftw3f:${PORTSDIR}/math/fftw3-float
.endif

pre-everything::
.if ${PORT_OPTIONS:MNUMPY}
	@${ECHO} ""
	@${ECHO} "* BEWARE!"
	@${ECHO} "* Using py-NumPY implies Fortran and GCC 4.6+ as hard dependencies"
	@${ECHO} "* and require all ports, depending on vigra, to set USE_GCC=yes"
	@${ECHO} ""
.endif

post-patch:
# FIXME: This is ugly
	@${RM} ${WRKSRC}/include/vigra/*.orig

.include <bsd.port.post.mk>
