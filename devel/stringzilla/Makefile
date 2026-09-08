PORTNAME=	stringzilla
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1.2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SIMD-accelerated string search/sort/hashes/fingerprints/edit distances
WWW=		https://ashvardanian.com/posts/stringzilla/ \
		https://github.com/ashvardanian/stringzilla

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ashvardanian
GH_PROJECT=	StringZilla
GH_TUPLE=	ashvardanian:ForkUnion:7f52520:forkunion/forkunion

CMAKE_ON=	STRINGZILLA_INSTALL
CMAKE_OFF=	STRINGZILLA_BUILD_TEST \
		STRINGZILLA_BUILD_BENCHMARK
CMAKE_TESTING_ON=	STRINGZILLA_BUILD_TEST
CMAKE_ARGS=	-DSTRINGZILLA_INCLUDE_INSTALL_DIR=include

CXXFLAGS+=	-g
LDFLAGS+=	-lpthread

# tests as of 5.1.2: 100% tests passed out of 6

.include <bsd.port.mk>
