PORTNAME=	libsimdpp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1-400
DISTVERSIONSUFFIX=	-g9dac213d
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only zero-overhead C++ wrapper of SIMD instructions

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

PORTSCOUT=	limit:^[v1-9]

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	p12tic

NO_BUILD=	yes
NO_ARCH=	yes

TEST_TARGET=	check

PLIST_SUB=	VER="${PORTVERSION:R}"

.include <bsd.port.mk>
