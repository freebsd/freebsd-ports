# Created by:	Baptiste Daroussin <bapt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mdds
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
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
	@${MKDIR} ${PREFIX}/include/mdds
	@${MKDIR} ${PREFIX}/include/mdds/compat
	@${MKDIR} ${PREFIX}/include/mdds/hash_container
	@${INSTALL_DATA} ${WRKSRC}/include/mdds/*.hpp ${PREFIX}/include/mdds
	@${INSTALL_DATA} ${WRKSRC}/include/mdds/*.inl ${PREFIX}/include/mdds
	@${INSTALL_DATA} ${WRKSRC}/include/mdds/compat/*.hpp ${PREFIX}/include/mdds/compat
	@${INSTALL_DATA} ${WRKSRC}/include/mdds/hash_container/*.hpp ${PREFIX}/include/mdds/hash_container
	@${INSTALL_DATA} ${WRKSRC}/misc/mdds.pc ${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
