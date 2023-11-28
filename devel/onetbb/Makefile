PORTNAME=	onetbb
PORTVERSION=	2021.11.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Library that provides thread building blocks
WWW=		https://software.intel.com/oneapi/onetbb

LICENSE=	APACHE20

LIB_DEPENDS=	libhwloc.so.15:devel/hwloc2

USES=		cmake compiler:c++11-lang tar:tgz

CMAKE_ARGS+=	-DTBB_STRICT:BOOL=FALSE \
		-DCMAKE_INSTALL_DOCDIR:PATH="${DOCSDIR}" \
		-DCMAKE_HWLOC_2_LIBRARY_PATH:PATH="${LOCALBASE}/lib/libhwloc.so" \
		-DCMAKE_HWLOC_2_INCLUDE_PATH:PATH="${LOCALBASE}/include"

# Many symbols in the linker version scripts are undefined because link time
# optimization (-flto=thin) removes them. Suppress errors with lld >= 17 due to
# these undefined symbols.
LDFLAGS+=	-Wl,--undefined-version

CONFLICTS=	tbb

USE_GITHUB=	yes
GH_ACCOUNT=	oneapi-src
GH_PROJECT=	oneTBB

USE_LDCONFIG=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

# Pkgconfig: tbb.pc (on 64bit arch) vs tbb32.pc
PLIST_SUB=	PCSUFX="${PCSUFX}" DBGSUFX="${DBGSUFX}"

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
DBGSUFX=	_debug
.endif

.if ${ARCH} == i386 || ${ARCH} == powerpc || ${ARCH:Marmv?}
PCSUFX=	32
.endif
.include <bsd.port.post.mk>
