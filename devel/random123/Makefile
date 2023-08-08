PORTNAME=	random123
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.0-5
DISTVERSIONSUFFIX=	-g9545ff6
CATEGORIES=	devel
MASTER_SITES=	https://github.com/GlobalArrays/ga/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Counter-based random number generators for C, C++ and CUDA
WWW=		https://github.com/DEShawResearch/random123

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	DEShawResearch

MAKEFILE=	GNUmakefile

NO_ARCH=	yes
NO_BUILD=	yes

INSTALL_TARGET=	install-include
TEST_TARGET=	check

.include <bsd.port.mk>
