PORTNAME=	pfstools
DISTVERSION=	2.1.0
PORTREVISION=	24
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	fbsd@any.com.ru
COMMENT=	Tools for manipulating HDR images and video frames
WWW=		https://pfstools.sourceforge.net/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash

CONFLICTS=	pfstmo-1.* pfscalibration-1.*

CFLAGS+=	-I${LOCALBASE}/include/Imath
LDFLAGS+=	-lthr

USES=		cmake cpe tar:tgz dos2unix jpeg perl5
USE_CXXSTD=	c++14
USE_PERL5=	run
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON \
		-DWITH_MATLAB=OFF \
		-DBASH_EXECUTABLE:STRING=${LOCALBASE}/bin/bash \
		-DPERL_EXECUTABLE:STRING=${PERL}

DOS2UNIX_GLOB=	*.txt *.cmake \
		*.h *.c *.cpp \
		*.1

MANCOMPRESSED=	yes

OPTIONS_DEFINE=	TIFF OPENEXR IMAGEMAGICK NETPBM \
		OCTAVE FFTW GSL \
		ALIGN GLVIEW VIEW \
		OPENMP
OPTIONS_DEFAULT=	TIFF FFTW GSL
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=	yes
OCTAVE_DESC=	Compile octave interface functions
GSL_DESC=	Use Gnu Scientific Libarary required for some TMOs
ALIGN_DESC=	Compile pfsalign, requires OpenCV w/NONFREE and libexif
VIEW_DESC=	Compile pfsview, requires QT5
GLVIEW_DESC=	Compile pfsglview, requires GLUT

TIFF_CMAKE_BOOL=	WITH_TIFF
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff

OPENEXR_CMAKE_BOOL=	WITH_OpenEXR
OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr \
			libImath.so:math/Imath

IMAGEMAGICK_CMAKE_BOOL=	WITH_ImageMagick
IMAGEMAGICK_USES=	magick:6

NETPBM_CMAKE_BOOL=	WITH_NetPBM
NETPBM_LIB_DEPENDS=	libnetpbm.so:graphics/netpbm
NETPBM_IMPLIES=		TIFF

OCTAVE_CMAKE_BOOL=	WITH_Octave
OCTAVE_PATCH_DEPENDS=	octave-config:math/octave
OCTAVE_BUILD_DEPENDS=	mkoctfile:math/octave
OCTAVE_RUN_DEPENDS=	octave:math/octave
OCTAVE_USES=		shebangfix
OCTAVE_CXXFLAGS=	-std=c++11

FFTW_CMAKE_BOOL=	WITH_FFTW
FFTW_CMAKE_ON=		-DFFTW_INCLUDE_DIRS=${LOCALBASE}/include
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3 \
			libfftw3f.so:math/fftw3-float

GSL_CMAKE_BOOL=		WITH_GSL
GSL_LIB_DEPENDS=	libgsl.so:math/gsl

ALIGN_CMAKE_BOOL=	WITH_OpenCV # requires NONFREE=on which isn't a default
ALIGN_LIB_DEPENDS=	libopencv_nonfree.so:graphics/opencv \
			libexif.so:graphics/libexif

GLVIEW_CMAKE_BOOL=	WITH_pfsglview
GLVIEW_CMAKE_ON=	-DGLUT_INCLUDE_DIRS=${LOCALBASE}/include
GLVIEW_USES=		gl
GLVIEW_USE=		GL=glut GL=gl,glu

VIEW_CMAKE_BOOL=	WITH_QT
VIEW_USES=		gl qt:5
VIEW_USE=		GL=glut GL=gl,glu QT=core,gui,widgets,buildtools:build,qmake:build

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGEMAGICK} && !${PORT_OPTIONS:MOPENMP}
USES+=		compiler:c++11-lib
.endif

.if ${PORT_OPTIONS:MOCTAVE}
OCTAVE_BASE?=	${LOCALBASE}
OCTAVE_VERSION!=${OCTAVE_BASE}/bin/octave-config -v 2>&1 || ${ECHO} "0"
OCTAVE_SITE_OCT!=${OCTAVE_BASE}/bin/octave-config --oct-site-dir 2>&1 || ${ECHO} ""
OCTAVE_SITE_M!=	${OCTAVE_BASE}/bin/octave-config --m-site-dir 2>&1 || ${ECHO} ""
PLIST_SUB=	OCTAVE_BASE=${OCTAVE_BASE} \
		OCTAVE_SITE_M=${OCTAVE_SITE_M:S|^${OCTAVE_BASE}/||} \
		OCTAVE_SITE_OCT=${OCTAVE_SITE_OCT:S|^${OCTAVE_BASE}/||}
SHEBANG_FILES=	src/octave/pfs*
SHEBANG_LANG=	octave
octave_OLD_CMD?=/usr/bin/octave
octave_CMD?=	${OCTAVE_BASE}/bin/octave-cli
.endif

.include <bsd.port.mk>
