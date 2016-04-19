# $FreeBSD$

PORTNAME=	mdds
PORTVERSION=	0.12.1
CATEGORIES=	devel
MASTER_SITES=	http://kohei.us/files/mdds/src/
PKGNAMESUFFIX=	0
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Multi-dimensional data index algorithm

LICENSE=	MIT

USES=		tar:bzip2
NO_ARCH=	yes
NO_BUILD=	yes

do-configure:
	@${SED} -e 's|@prefix@|${PREFIX}|' \
	    -e 's|@includedir@|$${prefix}/include|' \
	    -e 's|@VERSION@|${PORTVERSION}|' \
	    ${WRKSRC}/misc/mdds.pc.in > ${WRKSRC}/misc/mdds.pc

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}
	${INSTALL_DATA} ${WRKSRC}/misc/mdds.pc \
	    ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
