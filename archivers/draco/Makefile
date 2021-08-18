PORTNAME=	draco
DISTVERSION=	1.4.1-28
DISTVERSIONSUFFIX=	-g9bf5d2e
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

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	DRACO_TESTS # tests don't compile: https://github.com/google/draco/issues/731

.include <bsd.port.mk>
