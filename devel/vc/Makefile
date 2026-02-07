PORTNAME=	vc
DISTVERSION=	1.4.5
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SIMD Vector Classes for C++
WWW=		https://github.com/VcDevel/Vc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++14-lang # tests crash clang-13, see bug#264157

USE_GITHUB=	yes
GH_ACCOUNT=	VcDevel
GH_PROJECT=	Vc
GH_TUPLE=	VcDevel:vc-testdata:9ada1f3:testdata/tests/testdata \
		mattkretz:virtest:f7d03ef:virtest/tests/virtest

CMAKE_OFF=	BUILD_TESTING

# tests fail to compile, see https://github.com/VcDevel/Vc/issues/358
# tests crash clang, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=227339

.include <bsd.port.mk>
