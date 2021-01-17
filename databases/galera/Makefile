# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	galera
PORTVERSION?=	25.3.32
DISTVERSIONPREFIX?=	release_
CATEGORIES=	databases

MAINTAINER=	devel@galeracluster.com
COMMENT=	Synchronous multi-master replication engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: gu_int128.h: use of undeclared identifier '__bswap64_var'
BROKEN_armv6=		fails to compile: gu_int128.h: use of undeclared identifier '__bswap64_var'
BROKEN_armv7=		fails to compile: gu_int128.h: use of undeclared identifier '__bswap64_var'
BROKEN_riscv64=		fails to compile: gu_int128.h: use of undeclared identifier '__bswap64_var'
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
		${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs \
		objdump:devel/binutils
LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs

USES=		compiler:c++11-lang python:build cmake ssl

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TUPLE?=	codership:galera:${DISTVERSIONPREFIX}${PORTVERSION}${DISTVERSIONSUFFIX} \
		codership:wsrep-API:eab2d5d5a31672c0b7d116ef1629ff18392fd7d0:dummy/wsrep/src

CMAKE_ARGS+=	-DGALERA_REVISION=${GH_TAGNAME}

USE_RC_SUBR=	garb.sh

PLIST_FILES=	bin/garbd \
		lib/libgalera.so \
		lib/libgalera_smm.so

post-install:
	${RLN} ${STAGEDIR}/${PREFIX}/lib/libgalera_smm.so ${STAGEDIR}/${PREFIX}/lib/libgalera.so

.include <bsd.port.mk>
