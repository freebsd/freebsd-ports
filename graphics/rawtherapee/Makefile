# Created by: stas
# $FreeBSD$

PORTNAME=	rawtherapee
PORTVERSION=	4.2
CATEGORIES=	graphics
MASTER_SITES=	http://rawtherapee.com/shared/source/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Powerful RAW image processing application

LICENSE=	GPLv3

LIB_DEPENDS=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libiptcdata.so:${PORTSDIR}/graphics/libiptcdata \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3

USES=		cmake:outsource pkgconfig compiler:features desktop-file-utils dos2unix tar:xz
DOS2UNIX_REGEX=	.*\.(cc|h)
USE_GNOME=	gtk20 glib20
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include -fPIC ${PTHREAD_CFLAGS}
CXXFLAGS+=	-I${LOCALBASE}/include -fPIC ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CMAKE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS:C|-Wl,-rpath=${_GCC_RUNTIME}||:C|-L${_GCC_RUNTIME}||}"
CMAKE_ARGS+=	-DDOCDIR="${DOCSDIR}" \
		-DCREDITSDIR="${DOCSDIR}" \
		-DLICENCEDIR="${DOCSDIR}" \
		-DDESKTOPDIR="${DESKTOPDIR}" \
		-DDATADIR="${DATADIR}" \
		-DCMAKE_C_FLAGS="${CFLAGS:C|-Wl,-rpath=${_GCC_RUNTIME}||:C|-L${_GCC_RUNTIME}||}" \
		-DCMAKE_CXX_FLAGS="${CXXFLAGS:C|-Wl,-rpath=${_GCC_RUNTIME}||:C|-L${_GCC_RUNTIME}||}" \
		-DCACHE_NAME_SUFFIX="4.1"
SUB_FILES=	rawtherapee
SUB_LIST=	RTDIR="${RTDIR}"
INSTALLS_ICONS=	yes

RTDIR=		${PREFIX}/libdata/${PORTNAME}

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS OPENMP
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS OPENMP
OPENMP_DESC=		Enable multicore processing using OpenMP
OPTIMIZED_CFLAGS_DESC=	Use extra compiler optimizations (requires SSE support)

.include <bsd.port.pre.mk>

# -------------------------------------------------------------------
# USE_GCC must be late so the compiler feature checks work to detect
# that the base C++ standard library switched to libc++:
# We also must pin 4.8+ because 4.6 and 4.7 segfault on 10.0-RELEASE amd64
# wwhen compiling improcfun.cc:
USE_GCC=	yes

.if ${COMPILER_FEATURES:Mlibc++}
LDFLAGS+=	-L/usr/local/lib/c++
CXXFLAGS+=	-nostdinc++ -isystem /usr/local/include/c++/v1
CFLAGS+=	-isystem /usr/local/include/c++/v1
BUILD_DEPENDS+=	${LOCALBASE}/lib/c++/libstdc++.so:${PORTSDIR}/devel/libc++
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -fexpensive-optimizations \
		-funroll-loops -msse
CXXFLAGS+=	-O3 -ffast-math \
		-funroll-loops -msse
.endif
.endif

.if ${PORT_OPTIONS:MOPENMP}
CMAKE_ARGS+=	-DOPTION_OMP:BOOL=ON
.else
CMAKE_ARGS+=	-DOPTION_OMP:BOOL=OFF
.endif

#.if ${OSVERSION} >= 1100000
#BROKEN=		rawtherapee is known to crash on -HEAD and requires debugging that the maintainer cannot provide.
#.endif

# -------------------------------------------------------------------

post-patch:
	@${REINPLACE_CMD} -e 's#<auto_ptr.h>#<memory>#g' \
		${WRKSRC}/rtgui/darkframe.h \
		${WRKSRC}/rtgui/flatfield.h \
		${WRKSRC}/rtgui/icmpanel.h
	@${REINPLACE_CMD} -e 's#DESTINATION "$${CMAKE_INSTALL_PREFIX}/share/man/man1"#DESTINATION "${MANPREFIX}/man/man1/"#' \
		${WRKSRC}/CMakeLists.txt

# paranoia: run rawtherapee --help to be sure it finds all its
# shared libraries (this hinges on proper RPATH setting and propagation)
post-install:
	${SETENV} HOME=/dev/null ${STAGEDIR}${PREFIX}/bin/rawtherapee --help 2>&1 \
	| ${EGREP} -q "RawTherapee, version ${PKGVERSION:C/_.*//:C/,.*//}"

.include <bsd.port.post.mk>
