PORTNAME=	onetbb
PORTVERSION=	2022.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Library that provides thread building blocks
WWW=		https://software.intel.com/oneapi/onetbb

LICENSE=	APACHE20

LIB_DEPENDS=	libhwloc.so:devel/hwloc2

USES=		cmake compiler:c++11-lang localbase pathfix pkgconfig tar:tgz
USE_GITHUB=	yes
GH_ACCOUNT=	uxlfoundation
GH_PROJECT=	oneTBB
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_INSTALL_DOCDIR:PATH="${DOCSDIR}" \
		-DTBB_STRICT:BOOL=FALSE

# Many symbols in the linker version scripts are undefined because link time
# optimization (-flto=thin) removes them. Suppress errors with lld >= 17 due to
# these undefined symbols.
LDFLAGS+=	-Wl,--undefined-version

CONFLICTS=	tbb

# Pkgconfig: tbb.pc (on 64bit arch) vs tbb32.pc
PLIST_SUB=	DBGSUFX="${DBGSUFX}" \
		PCSUFX="${PCSUFX}"

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
DBGSUFX=	_debug
.endif

.if ${ARCH} == i386 || ${ARCH} == powerpc || ${ARCH:Marmv?}
PCSUFX=		32
.endif
.include <bsd.port.post.mk>
