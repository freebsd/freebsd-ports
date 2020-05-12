# $FreeBSD$

PORTNAME=		PrusaSlicer
DISTVERSIONPREFIX=	version_
DISTVERSION=		2.2.0
PORTREVISION=	2
CATEGORIES=		cad
MASTER_SITES=https://github.com/CGAL/cgal/archive/releases/:cgal
DISTFILES=CGAL-5.0.2.tar.gz:cgal

MAINTAINER=	teodorsigaev@gmail.com
COMMENT=	Slicing application for 3D printers

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtbb.so:devel/tbb \
		libboost_log.so:devel/boost-libs \
		libHalf.so:graphics/ilmbase \
		libnlopt.so:math/nlopt \
		libwx_gtk3u_core-3.1.so:x11-toolkits/wxgtk31 \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libopenvdb.so:misc/openvdb \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
BUILD_DEPENDS=	cereal>=1.2.2:devel/cereal \
		eigen>=3.3:math/eigen3 \
		googletest>=1.7:devel/googletest \
		boost-libs>=1.64:devel/boost-libs \
		wx31-gtk3>=3.1:x11-toolkits/wxgtk31 \
		cmake>=3.2:devel/cmake \
		ninja>=1.8.2:devel/ninja \
		openvdb>=6.1.0:misc/openvdb \
		gmp>=6.1.2:math/gmp \
		mpfr>=4.0.2:math/mpfr \
		qt5-buildtools>=0:devel/qt5-buildtools

USES=		cmake gettext gl iconv pkgconfig

CMAKE_ARGS+=	-DwxWidgets_CONFIG_EXECUTABLE=${LOCALBASE}/bin/wxgtk3u-3.1-config \
		-DCGAL_DIR=${WRKSRC}/CGAL/lib/cmake/CGAL
CMAKE_INSTALL_PREFIX=	${PREFIX}/${PORTNAME}

USE_GITHUB=	yes
USE_GL=		gl glu glew
GH_ACCOUNT=	prusa3d

post-patch:
	${REINPLACE_CMD} -e 's,%%WRKSRC%%,${WRKSRC},' \
		${WRKSRC}/CMakeLists.txt

pre-configure:
	cd ${WRKDIR}/cgal-releases-CGAL-5.0.2 && \
	${CMAKE_BIN} -E remove CGALConfig-installation-dirs.cmake && \
	${MKDIR} build && cd build && \
	${CMAKE_BIN} -DCMAKE_INSTALL_PREFIX=${WRKSRC}/CGAL \
		-DCMAKE_PREFIX_PATH=${WRKSRC}/CGAL \
		-DCMAKE_MODULE_PATH=${WRKSRC}/cmake/modules \
		-DCMAKE_BUILD_TYPE=Release .. && \
	${BSDMAKE} all install

.include <bsd.port.mk>
