# $FreeBSD$

PORTNAME=	gmic
DISTVERSIONPREFIX=	v.
DISTVERSION=	2.2.3
CATEGORIES=	graphics
MASTER_SITES=	http://gmic.eu/:gmic_stdlib
DISTFILES=	gmic_stdlib.h:gmic_stdlib
DIST_SUBDIR=	${PORTNAME}-${DISTVERSIONFULL}
EXTRACT_ONLY=	dtschump-gmic-${DISTVERSIONFULL}_GH0.tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for image processing

LICENSE=	CeCILL
LICENSE_NAME=	CeCILL
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_FreeBSD_10=	error: "c++ crashes, clang-5 and 6 fail: undefined reference to `__atomic_load'"

BUILD_DEPENDS=	${LOCALBASE}/include/CImg.h:graphics/cimg
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libGraphicsMagick++.so:graphics/GraphicsMagick \
		libIlmImf.so:graphics/OpenEXR \
		libImath-2_2.so:graphics/ilmbase \
		libomp.so:devel/openmp \
		libopencv_core.so:graphics/opencv-core \
		libopencv_video.so:graphics/opencv \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake:outsource compiler:c++11-lang jpeg pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dtschump
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_LIB_STATIC
CMAKE_ON=	ENABLE_DYNAMIC_LINKING

PLIST_FILES=	bin/gmic \
		include/gmic.h \
		lib/libgmic.so \
		lib/libgmic.so.1 \
		man/man1/gmic.1.gz

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/gmic_stdlib.h ${WRKSRC}/src/

.include <bsd.port.mk>
