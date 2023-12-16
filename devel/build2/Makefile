PORTNAME=	build2
DISTVERSION=	0.16.0
CATEGORIES=	devel
MASTER_SITES=	https://download.build2.org/${DISTVERSION}/
DISTNAME=	build2-toolchain-${DISTVERSION}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Cross-platform toolchain for building and packaging C++ code
WWW=		https://build2.org

LICENSE=	BSD2CLAUSE BSD3CLAUSE MIT
LICENSE_COMB=	multi

BROKEN_powerpc=	fails in stage: Invalid data memory access

USES=		gmake pkgconfig sqlite tar:xz

# Fix build on i386/powerpc: error: timestamp is not lock-free on this architecture
CXXFLAGS_i386=		-DLIBBUILD2_ATOMIC_NON_LOCK_FREE
CXXFLAGS_powerpc=	-DLIBBUILD2_ATOMIC_NON_LOCK_FREE

# warning: clang@/usr/local/libexec/ccache/clang looks like a ccache wrapper
#  info: ccache cannot be used as a C compiler
#  info: use config.c to override
NO_CCACHE=	yes

PLIST_SUB=	SOVERSION=${DISTVERSION:R}

OPTIONS_DEFINE=	DOCS

pre-build:
# phase 1
	@cd ${WRKSRC}/build2 && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} bootstrap.gmake ${_MAKE_JOBS}

do-build:
# phase 2
	@cd ${WRKSRC}/build2 && ${SETENV} ${MAKE_ENV} ./build2/b-boot \
		config.cxx=${CXX} \
		config.cxx.coptions="${CXXFLAGS}" \
		config.cxx.loptions="${LDFLAGS} -s" \
		config.bin.lib=static \
		build2/exe{b} \
		-V -j ${MAKE_JOBS_NUMBER} -J ${MAKE_JOBS_NUMBER}
	${MV} ${WRKSRC}/build2/build2/b ${WRKSRC}/build2/build2/b-boot

do-install:
# "stage" (local installation)
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build2/build2/b-boot configure \
		config.cxx=${CXX} \
		config.cxx.coptions="${CXXFLAGS}" \
		config.cxx.loptions="${LDFLAGS} -s" \
		config.bin.lib=shared \
		config.import.libsqlite3= \
		config.bin.rpath=${PREFIX}/lib \
		config.install.chroot=${STAGEDIR} \
		config.install.root=${PREFIX}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build2/build2/b-boot install: build2/ bpkg/ bdep/ \
		-V -j ${MAKE_JOBS_NUMBER} -J ${MAKE_JOBS_NUMBER}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build2/build2/b-boot install: '!config.install.scope=project' libbuild2-*/ \
		-V -j ${MAKE_JOBS_NUMBER} -J ${MAKE_JOBS_NUMBER}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpkg-config-0.1.so

.include <bsd.port.mk>
