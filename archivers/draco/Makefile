PORTNAME=	draco
DISTVERSION=	1.4.3
CATEGORIES=	archivers
PKGNAMESUFFIX=	-3d-compression

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for compressing and decompressing 3D meshes and point clouds

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TUPLE=	google:googletest:16f637f:googletest/../googletest # tests require the googletest source tree for some reason, see https://github.com/google/draco/issues/731

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	DRACO_TESTS
CMAKE_TESTING_TARGET=	draco_tests draco_factory_tests

post-test: # see https://github.com/google/draco/issues/753
	@cd ${BUILD_WRKSRC} && \
		./draco_tests && \
		./draco_factory_tests

.include <bsd.port.mk>
