PORTNAME=	wrapland
DISTVERSIONPREFIX=	v
DISTVERSION=	0.601.0
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Qt/C++ library wrapping libwayland
WWW=		https://github.com/winft/wrapland

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		microsoft-gsl>0:devel/microsoft-gsl \
		wayland-protocols>=1.27:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland
RUN_DEPENDS=	microsoft-gsl>0:devel/microsoft-gsl

USES=		cmake:testing gl kde:6 pkgconfig qt:6
USE_GITHUB=	yes
USE_GL=		egl
USE_KDE=	ecm:build
USE_LDCONFIG=	yes
USE_QT=		base
GH_ACCOUNT=	winft
LDFLAGS+=	-Wl,--as-needed # GL, xkbcommon
PLIST_SUB=	VERSION=${PORTVERSION}

# XXX Drop after FreeBSD 13.2 EOL around 2024-07-01 (don't forget distinfo)
.if ${CXX} == c++ && exists(/usr/lib/libc++.so)
.if !exists(/usr/include/c++/v1/__ranges/as_rvalue_view.h) || make(makesum) || make(fetch)
USES+=		llvm:min=16,build,export
PATH:=		${LLVM_PREFIX}/bin:${PATH} # XXX _CMAKE_TOOLCHAIN_SUFFIX vs. devel/llvm*
CONFIGURE_ENV+=	CC="${CC}" CXX="${CXX}" CPP="${CPP}"

# XXX Move into separate port and standardize via USES
GH_TUPLE+=	llvm:llvm-project:llvmorg-16.0.1:libcxx
CXXFLAGS+=	-nostdinc++ -isystem${WRKDIR}/libcxx_prefix/include/c++/v1
# Don't link against new libc++ as it's not necessary
#LDFLAGS+=	-nostdlib++ -L${WRKDIR}/libcxx_prefix/lib -l:libc++.a -lcxxrt

pre-configure:	bundled-libcxx
bundled-libcxx:
	@${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
		-DLIBCXX_INCLUDE_BENCHMARKS:BOOL=OFF \
		-DCMAKE_INSTALL_PREFIX:PATH=${WRKDIR}/libcxx_prefix \
		-B ${WRKDIR}/libcxx_build -S ${WRKSRC_libcxx}/libcxx
	@${DO_MAKE_BUILD:NDESTDIR*} install -C ${WRKDIR}/libcxx_build
.endif
.endif # exists(/usr/lib/libc++.so)

.include <bsd.port.mk>
