PORTNAME=	bifrost
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
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

GH_ACCOUNT=	pmelsted

.include <bsd.port.mk>
