# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	galera
PORTVERSION?=	25.3.28
DISTVERSIONPREFIX?=	release_
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	devel@galeracluster.com
COMMENT=	Synchronous multi-master replication engine

LICENSE=	GPLv2

BROKEN_aarch64=		fails to compile: gu_int128.h: use of undeclared identifier '__bswap64_var'
BROKEN_armv6=		fails to compile: gu_int128.h: use of undeclared identifier '__bswap64_var'
BROKEN_armv7=		fails to compile: gu_int128.h: use of undeclared identifier '__bswap64_var'
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

BUILD_DEPENDS=	checkmk:devel/check \
		${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs

USES=		compiler:c++11-lang python:build scons ssl

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TUPLE?=	codership:galera:${DISTVERSIONPREFIX}${PORTVERSION}${DISTVERSIONSUFFIX} \
		codership:wsrep-API:eab2d5d5a31672c0b7d116ef1629ff18392fd7d0:dummy/wsrep/src

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

BOOSTPOOL_MAKE_ARGS=	boost_pool=1
BPOSTATIC_MAKE_ARGS=	bpostatic=${LOCALBASE}/lib/libboost_program_options.a
DEBUG_MAKE_ARGS=	debug=0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/garb/garbd ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/libgalera_smm.so ${STAGEDIR}${PREFIX}/lib/
	@(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libgalera_smm.so \
		libgalera.so)

.include <bsd.port.mk>
