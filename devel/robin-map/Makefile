PORTNAME=	robin-map
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Fast hash map and hash set
WWW=		https://github.com/Tessil/robin-map

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	Tessil

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/tsl/robin_growth_policy.h \
		include/tsl/robin_hash.h \
		include/tsl/robin_map.h \
		include/tsl/robin_set.h

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tsl
	${INSTALL_DATA} ${WRKSRC}/include/tsl/* ${STAGEDIR}${PREFIX}/include/tsl/

.include <bsd.port.mk>
