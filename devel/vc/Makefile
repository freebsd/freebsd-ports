PORTNAME=	vc
DISTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SIMD Vector Classes for C++

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	VcDevel
GH_PROJECT=	Vc
GH_TUPLE=	VcDevel:vc-testdata:9ada1f3:testdata/tests/testdata \
		mattkretz:virtest:f7d03ef:virtest/tests/virtest

CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
