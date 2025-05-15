PORTNAME=	bifrost
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.5
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Parallel construction, indexing and querying of de Bruijn graphs
WWW=		https://github.com/pmelsted/bifrost

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	Requires a 64-bit processor

USES=		cmake
USE_GITHUB=	yes

CMAKE_ARGS=	-DCOMPILATION_ARCH=${CPUTYPE:UOFF}

CXXFLAGS+=	-Wno-unqualified-std-cast-call

GH_ACCOUNT=	pmelsted

.include <bsd.port.pre.mk>

# Build fails with clang19, but succeeds with gcc13
# Have not figured out where this sz_link member is even supposed to come from
# DataStorage.tcc:81:69: error: no member named 'sz_link' in 'DataStorage<Unitig_data_t>'
.if ${OSVERSION} > 1500000
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
