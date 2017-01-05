# Created by: stas
# $FreeBSD$

PORTNAME=	rawtherapee
PORTVERSION=	4.2.99.git000
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://rawtherapee.com/shared/source/
PKGNAMESUFFIX=	-devel

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Powerful RAW image processing application

LICENSE=	GPLv3

LIB_DEPENDS=	\
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libexpat.so:textproc/expat2 \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libgtkmm-3.0.so:x11-toolkits/gtkmm30 \
		libiptcdata.so:graphics/libiptcdata \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libsigc-2.0.so:devel/libsigc++20 \
		libtiff.so:graphics/tiff

USE_GITHUB=	yes
GH_TUPLE=	Beep6581:RawTherapee:70a79772

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils dos2unix gettext-runtime jpeg pkgconfig tar:xz
DOS2UNIX_REGEX=	.*\.(cc|h)
USE_GNOME=	atkmm cairo cairomm glibmm pangomm gtk30
USE_XORG+=	x11
USE_LDCONFIG=	yes
USE_BINUTILS=	yes
CFLAGS+=	-I${LOCALBASE}/include -fPIC
CXXFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}"
CMAKE_ARGS+=	-DDOCDIR="${DOCSDIR}" \
		-DCREDITSDIR="${DOCSDIR}" \
		-DLICENCEDIR="${DOCSDIR}" \
		-DDESKTOPDIR="${DESKTOPDIR}" \
		-DDATADIR="${DATADIR}" \
		-DCACHE_NAME_SUFFIX=""
SUB_FILES=	rawtherapee
SUB_LIST=	RTDIR="${RTDIR}"
INSTALLS_ICONS=	yes

RTDIR=		${PREFIX}/libdata/${PORTNAME}

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS OPENMP NATIVE
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS OPENMP
OPENMP_DESC=		Enable multicore processing using OpenMP
OPTIMIZED_CFLAGS_DESC=	Use extra compiler optimizations (requires SSE2 support)
NATIVE_DESC=		Use -march=native for compilation (do not use for generic packages!)

OPENMP_CMAKE_BOOL=	OPTION_OMP

.if defined(PACKAGE_BUILDING)
CMAKE_ARGS+=	-DPROC_TARGET_NUMBER="1"
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -funroll-loops -msse2
CXXFLAGS+=	-O3 -funroll-loops -msse2
.endif
.endif

.if ${PORT_OPTIONS:MNATIVE}
CMAKE_ARGS+=	-DPROC_TARGET_NUMBER="2"
.endif

.if ${ARCH} == amd64 && ${COMPILER_TYPE} == clang
# Enable OpenMP support with Clang 3.9.
BUILD_DEPENDS+=	clang39:devel/llvm39
LIB_DEPENDS+=	libomp.so.0:devel/openmp

CPP=		clang-cpp39
CC=		clang39
CXX=		clang++39

# FIXME: At least in 3.7.0 and 3.7.1, Clang doesn't find libomp.so
# itself. Furthermore, there may be a regression in 3.7.1 because we now
# need to explicitly link to libm.so as well.
OPENMP_FLAGS=	-L${LOCALBASE}/lib -lm -lomp
LDFLAGS+=	${OPENMP_FLAGS}

# In cmake, the CMP0056 policy must be explicitly set to NEW to ensure
# linker flags are passed.
# See: https://cmake.org/cmake/help/v3.4/policy/CMP0056.html
CMAKE_ARGS+=	-DCMAKE_POLICY_DEFAULT_CMP0056:STRING=NEW
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#<auto_ptr.h>#<memory>#g' \
		${WRKSRC}/rtgui/darkframe.h \
		${WRKSRC}/rtgui/flatfield.h \
		${WRKSRC}/rtgui/icmpanel.h
	@${REINPLACE_CMD} -e 's#DESTINATION "$${CMAKE_INSTALL_PREFIX}/share/man/man1"#DESTINATION "${MANPREFIX}/man/man1/"#' \
		${WRKSRC}/CMakeLists.txt
	${RM} ${WRKSRC}/rtengine/dcraw.patch \
		${WRKSRC}/rtengine/dcraw.c

.ifdef(USE_GITHUB)
pre-configure:
	${CP} ${FILESDIR}/ReleaseInfo.cmake ${WRKSRC}/
.endif

.include <bsd.port.post.mk>
