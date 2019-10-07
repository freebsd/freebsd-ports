# $FreeBSD$

PORTNAME=	robin-map
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
CATEGORIES=	devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Fast hash map and hash set

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	Tessil

NO_BUILD=	yes

PLIST_FILES=	include/tsl/robin_growth_policy.h \
		include/tsl/robin_hash.h \
		include/tsl/robin_map.h \
		include/tsl/robin_set.h

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tsl
	${INSTALL_DATA} ${WRKSRC}/include/tsl/* ${STAGEDIR}${PREFIX}/include/tsl/

.include <bsd.port.mk>
