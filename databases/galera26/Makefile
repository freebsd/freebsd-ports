PORTNAME=	galera
DISTVERSIONPREFIX=	mariadb-
DISTVERSION=	26.4.22
PORTREVISION=	2
CATEGORIES=	databases
PKGNAMESUFFIX=	26

MAINTAINER=	devel@galeracluster.com
COMMENT=	Synchronous multi-master replication engine
WWW=		https://galeracluster.com/

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
		objdump:devel/binutils
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USES=		cmake compiler:c++11-lang python:build ssl

USE_GITHUB=	yes
GH_TUPLE?=	mariadb:galera:${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX} \
		codership:wsrep-API:65608d3f503ba9f4c170fc4e01c539be9fafd46c:dummy/wsrep/src
USE_LDCONFIG=	yes
USE_RC_SUBR=	garb.sh

CMAKE_ARGS+=	-DGALERA_REVISION=${GH_TAGNAME}

CONFLICTS_INSTALL=	galera

PLIST_FILES=	bin/garbd \
		lib/libgalera.so \
		lib/libgalera_smm.so

post-install:
	${RLN} ${STAGEDIR}/${PREFIX}/lib/libgalera_smm.so ${STAGEDIR}/${PREFIX}/lib/libgalera.so

.include <bsd.port.mk>
