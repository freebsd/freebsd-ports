PORTNAME=	dht
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.27
CATEGORIES=	devel

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Mainline variant of Kademlia Distributed Hash Table (DHT)
WWW=		http://www.pps.univ-paris-diderot.fr/~jch/software/bittorrent/

LICENSE=	MIT

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	jech

USE_LDCONFIG=	yes
MAKE_ENV=	STAGEDIR="${STAGEDIR}"

MAKEFILE=	${FILESDIR}/BSDmakefile

post-build:
	${SETENV} ${MAKE_ENV} ${MAKE} -C ${WRKSRC} -f \
		${FILESDIR}/Makefile.example

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/dht

post-install:
	${SETENV} ${MAKE_ENV} ${MAKE} -C ${WRKSRC} -f \
		${FILESDIR}/Makefile.example install

.include <bsd.port.mk>
