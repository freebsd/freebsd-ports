PORTNAME=	libcsptr
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.4-24
DISTVERSIONSUFFIX=	-gac73451
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Smart pointers for the (GNU) C programming language
WWW=		https://snai.pe/posts/c-smart-pointers \
		https://github.com/Snaipe/libcsptr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	check>0:devel/check

USES=		cmake:testing localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Snaipe

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	LIBCSPTR_TESTS # tests fail to compile, see https://github.com/Snaipe/libcsptr/issues/23
CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4 compatibility, see https://github.com/Snaipe/libcsptr/issues/31

.include <bsd.port.mk>
