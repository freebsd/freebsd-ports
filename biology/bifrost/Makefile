PORTNAME=	bifrost
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Parallel construction, indexing and querying of de Bruijn graphs
WWW=		https://github.com/pmelsted/bifrost

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# Requires a 64-bit processor
ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le riscv64

USES=		cmake
USE_GITHUB=	yes

GH_ACCOUNT=	pmelsted

.include <bsd.port.mk>
