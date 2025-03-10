PORTNAME=	lzfse
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.0
PORTEPOCH=	1
CATEGORIES=	archivers

PATCH_SITES=	https://github.com/lzfse/lzfse/commit/
PATCHFILES=	570967857b31ff77eb355cdf8eb583fbb4d70177.patch:-p1

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Lempel-Ziv style data compression algorithm
WWW=		https://github.com/lzfse/lzfse

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes

TEST_TARGET=	test

CMAKE_OFF=	CMAKE_C_EXTENSIONS

.include <bsd.port.mk>
