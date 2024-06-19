PORTNAME=	hyprutils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.3
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Hyprland utilities library used across the ecosystem
WWW=		https://github.com/hyprwm/hyprutils

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lib cmake:testing
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	hyprwm
PLIST_SUB=	VERSION=${DISTVERSION:C/-.*//}

# XXX Drop after FreeBSD 13.2 EOL around 2024-07-01 (don't forget distinfo)
.if ${CXX} == c++ && exists(/usr/lib/libc++.so)
.if !exists(/usr/include/c++/v1/expected) || make(makesum) || make(fetch)
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
