PORTNAME=	robin-map
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
CATEGORIES=	devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Fast hash map and hash set
WWW=		https://github.com/Tessil/robin-map

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	Tessil

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/tsl/robin_growth_policy.h \
		include/tsl/robin_hash.h \
		include/tsl/robin_map.h \
		include/tsl/robin_set.h \
		share/cmake/tsl-robin-map/tsl-robin-mapConfig.cmake \
		share/cmake/tsl-robin-map/tsl-robin-mapConfigVersion.cmake \
		share/cmake/tsl-robin-map/tsl-robin-mapTargets.cmake

.include <bsd.port.mk>
