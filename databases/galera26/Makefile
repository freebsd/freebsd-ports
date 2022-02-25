# Created by: Nicolas Embriz <nbari@tequila.io>

PORTNAME=	galera
PORTVERSION=	26.4.11
DISTVERSIONPREFIX=	release_
CATEGORIES=	databases
PKGNAMESUFFIX=	26

MAINTAINER=	devel@galeracluster.com
COMMENT=	Synchronous multi-master replication engine

LICENSE=	GPLv2

NOT_FOR_ARCHS=		i386 powerpc
# On i386 or powerpc older versions of clang produce:
#   cannot compile this atomic library call yet ... __atomic_add_fetch
# whereas newer ones generate a call to __atomic_add_fetch which ends up with
# undefined reference at link time:
#   undefined reference to `__atomic_fetch_add_8'
# https://bugs.llvm.org//show_bug.cgi?id=23262
# https://bugs.llvm.org//show_bug.cgi?id=24908
# https://tracker.crystax.net/issues/1263
NOT_FOR_ARCHS_REASON_i386=Uses 64 bit atomics that clang cannot generate on i386
NOT_FOR_ARCHS_REASON_powerpc=Uses 64 bit atomics that clang cannot generate on powerpc

BUILD_DEPENDS=	checkmk:devel/check \
		${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs \
		objdump:devel/binutils
LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs

USES=		compiler:c++11-lang python:build cmake ssl

USE_GITHUB=	yes
GH_TUPLE?=	codership:galera:${DISTVERSIONPREFIX}${PORTVERSION}${DISTVERSIONSUFFIX} \
		codership:wsrep-API:02ed17238cee97b5a3ea2495ca87b63570403f01:dummy/wsrep/src

CMAKE_ARGS+=	-DGALERA_REVISION=${GH_TAGNAME}

USE_LDCONFIG=	yes
USE_RC_SUBR=	garb.sh

CONFLICTS_INSTALL=      galera

PLIST_FILES=	bin/garbd \
		lib/libgalera.so \
		lib/libgalera_smm.so

post-install:
	${RLN} ${STAGEDIR}/${PREFIX}/lib/libgalera_smm.so ${STAGEDIR}/${PREFIX}/lib/libgalera.so

.include <bsd.port.mk>
