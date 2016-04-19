# $FreeBSD$

PORTNAME=	mdds
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	http://kohei.us/files/mdds/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Multi-dimensional data index algorithm

LICENSE=	MIT

USES=		tar:bzip2
NO_ARCH=	yes
NO_BUILD=	yes

API_VERSION=	1.0
PLIST_SUB=	API_VERSION=${API_VERSION}

do-configure:
	@${SED} -e 's|@API_VERSION@|${API_VERSION}|' \
	    -e 's|@VERSION@|${PORTVERSION}|' \
	    -e 's|@includedir@|$${prefix}/include|' \
	    -e 's|@prefix@|${PREFIX}|' \
	    ${WRKSRC}/misc/mdds.pc.in > \
	    ${WRKSRC}/misc/mdds-${API_VERSION}.pc

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/mdds-${API_VERSION}/mdds
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}${PREFIX}/include/mdds-${API_VERSION} \
	    "-not -name *.orig")
	${INSTALL_DATA} ${WRKSRC}/misc/mdds-${API_VERSION}.pc \
	    ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
