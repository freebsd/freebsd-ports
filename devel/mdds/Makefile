# $FreeBSD$

PORTNAME=	mdds
PORTVERSION=	0.9.1
CATEGORIES=	devel
MASTER_SITES=	http://kohei.us/files/mdds/src/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Multi-dimensional data index algorithm

LICENSE=	MIT

PROJECTHOST=	multidimalgorithm

USE_BZIP2=	yes
NO_BUILD=	yes

do-configure:
	@${SED} -e 's|@prefix@|${PREFIX}|' \
	    -e 's|@includedir@|$${prefix}/include|' \
	    -e 's|@VERSION@|${PORTVERSION}|' \
	    ${WRKSRC}/misc/mdds.pc.in > ${WRKSRC}/misc/mdds.pc

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/mdds
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/mdds/compat
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/mdds/hash_container
	@${INSTALL_DATA} ${WRKSRC}/include/mdds/*.hpp ${STAGEDIR}${PREFIX}/include/mdds
	@${INSTALL_DATA} ${WRKSRC}/include/mdds/*.inl ${STAGEDIR}${PREFIX}/include/mdds
	@${INSTALL_DATA} ${WRKSRC}/include/mdds/compat/*.hpp ${STAGEDIR}${PREFIX}/include/mdds/compat
	@${INSTALL_DATA} ${WRKSRC}/include/mdds/hash_container/*.hpp ${STAGEDIR}${PREFIX}/include/mdds/hash_container
	@${INSTALL_DATA} ${WRKSRC}/misc/mdds.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
