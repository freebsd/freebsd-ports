PORTNAME=	art
DISTVERSION=	1.25.6
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/artpixls/ART/releases/download/${DISTVERSION}/
PKGNAMESUFFIX=	-raw-image-editor
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Raw image processing program
WWW=		https://art.pixls.us/ \
		https://github.com/artpixls/ART

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_armv7=	compilation fails: use of overloaded operator '[]' is ambiguous, see https://bitbucket.org/agriggio/art/issues/256/build-fails-on-32-bit-architectures-use-of
BROKEN_i386=	ld: error: undefined symbol: __atomic_load

EXTRACT_DEPENDS=	gtar:archivers/gtar # bsdtar(1) complains about hard links to itself
BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libraw_r.so:graphics/libraw \
		libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libfftw3f.so:math/fftw3-float \
		libharfbuzz.so:print/harfbuzz \
		liblensfun.so:graphics/lensfun \
		liblcms2.so:graphics/lcms2 \
		libOpenColorIO.so:graphics/opencolorio \
		libtiff.so:graphics/tiff

USES=		cmake compiler:c++11-lang desktop-file-utils gnome jpeg pkgconfig tar:xz xorg
USE_GNOME=	atk atkmm cairo cairomm glibmm gtkmm30 librsvg2
USE_XORG=	x11

EXTRACT_CMD=	gtar

CXXFLAGS+=	-I${LOCALBASE}/include/Imath # workaround for https://bitbucket.org/agriggio/art/issues/339/1241-build-fails-usr-local-include-ctl
LDFLAGS+=	-lpthread # otherwise build breaks on some systems: error: undefined symbol: pthread_create

OPTIONS_DEFINE=		CTL LTO MIMALLOC
OPTIONS_DEFAULT=	CTL LTO

CTL_DESC=		Enable support for the ACES Color Transformation Language
CTL_CMAKE_BOOL=		ENABLE_CTL
CTL_LIB_DEPENDS=	libIlmCtl.so:graphics/ctl \
			libImath.so:math/Imath \
			libOpenEXR.so:graphics/openexr \
			libpng16.so:graphics/png

LTO_CMAKE_BOOL=		WITH_LTO

MIMALLOC_DESC=		Enable mimalloc allocator
MIMALLOC_CMAKE_BOOL=	ENABLE_MIMALLOC
MIMALLOC_LIB_DEPENDS=	libmimalloc.so:devel/mimalloc
MIMALLOC_BROKEN=	mimalloc crashes, see https://github.com/microsoft/mimalloc/issues/1007

.if exists(/usr/include/omp.h)
OPTIONS_DEFINE+=	OPENMP
OPTIONS_DEFAULT+=	OPENMP

OPENMP_CMAKE_BOOL=	OPTION_OMP
.else
CMAKE_OFF=	OPTION_OMP
.endif

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/ART

.include <bsd.port.mk>
