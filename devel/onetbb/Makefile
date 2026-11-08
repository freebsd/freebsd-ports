PORTNAME=	onetbb
DISTVERSIONPREFIX=	v
DISTVERSION=	2023.1.0
PORTREVISION=	1
CATEGORIES=	devel
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
# https://github.com/uxlfoundation/oneTBB/pull/2194 (not in 2023.2.0)
PATCHFILES=	2deef980fcae7c141f11ba8fd6cefd262fcb01d0.patch:-p1

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Library that provides thread building blocks
WWW=		https://software.intel.com/oneapi/onetbb

LICENSE=	APACHE20

LIB_DEPENDS=	libhwloc.so:devel/hwloc2

USES=		cmake:testing compiler:c++11-lang localbase:ldflags pathfix pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	uxlfoundation
GH_PROJECT=	oneTBB

CONFLICTS=	tbb

# Many symbols in the linker version scripts are undefined because link time
# optimization (-flto=thin) removes them. Suppress errors with lld >= 17 due to
# these undefined symbols.
LDFLAGS+=	-Wl,--undefined-version

# Pkgconfig: tbb.pc (on 64bit arch) vs tbb32.pc
PLIST_SUB=	DBGSUFX="${DBGSUFX}" \
		PCSUFX="${PCSUFX}"

PORTDOCS=	README.md

CMAKE_TESTING_ON=	TBB_TEST

CMAKE_OFF=	TBB_STRICT \
		TBB_TEST
CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR:PATH="${DOCSDIR}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
DBGSUFX=	_debug
.endif

.if ${ARCH} == i386 || ${ARCH} == powerpc || ${ARCH:Marmv?}
PCSUFX=		32
.endif
.include <bsd.port.post.mk>
