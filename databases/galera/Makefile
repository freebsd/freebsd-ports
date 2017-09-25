# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	galera
PORTVERSION?=	25.3.21
DISTVERSIONPREFIX?=	release_
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	devel@galeracluster.com
COMMENT=	Synchronous multi-master replication engine

LICENSE=	GPLv2

BUILD_DEPENDS=	checkmk:devel/check \
		${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs

BROKEN_aarch64=		fails to compile: gu_int128.h: use of undeclared identifier '__bswap64_var'
BROKEN_armv6=		fails to compile: gu_int128.h: use of undeclared identifier '__bswap64_var'
NOT_FOR_ARCHS=		i386
# On i386 older versions of clang produce:
#   cannot compile this atomic library call yet ... __atomic_add_fetch
# whereas newer ones generate a call to __atomic_add_fetch which ends up with
# undefined reference at link time:
#   undefined reference to `__atomic_fetch_add_8'
# https://bugs.llvm.org//show_bug.cgi?id=23262
# https://bugs.llvm.org//show_bug.cgi?id=24908
# https://tracker.crystax.net/issues/1263
NOT_FOR_ARCHS_REASON_i386=Uses 64 bit atomics that clang cannot generate on i386

USES=		python:build scons ssl

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	codership

LDFLAGS+=	-lboost_program_options -lboost_system
MAKE_ARGS+=	revno=${GH_TAGNAME} system_asio=0 tests=0

USE_RC_SUBR=	garb.sh

# Abuse TEST_TARGET to append tests=1 (which is not a target, strictly
# speaking) at the end of the "scons ..." command so that it overrides
# tests=0 from ${MAKE_ARGS}. To rerun the tests a second time, remove
# all *.passed files: find ./work -name *.passed -print -delete
TEST_TARGET=	deterministic_tests=1 tests=1

PLIST_FILES=	bin/garbd \
		lib/libgalera.so \
		lib/libgalera_smm.so

OPTIONS_DEFINE=	BOOSTPOOL BPOSTATIC DEBUG

BOOSTPOOL_DESC=	Use boost pool allocator
BPOSTATIC_DESC=	Use static boost_program_options

.include <bsd.port.pre.mk>

# Clang is available on FreeBSD 9.x but the default
# compiler (e.g. /usr/bin/cc) is GCC. Force the usage of Clang.
.if ${OSVERSION} < 1000024
CC=		clang
CXX=		clang++
CPP=		clang-cpp
.endif

.if ${PORT_OPTIONS:MBOOSTPOOL}
MAKE_ARGS+=	boost_pool=1
.endif

.if ${PORT_OPTIONS:MBPOSTATIC}
MAKE_ARGS+=	bpostatic=${LOCALBASE}/lib/libboost_program_options.a
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=	debug=0
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/garb/garbd ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/libgalera_smm.so ${STAGEDIR}${PREFIX}/lib/
	@(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libgalera_smm.so \
		libgalera.so)

.include <bsd.port.post.mk>
