PORTNAME=	jam
DISTVERSION=	2.6.1
CATEGORIES=	devel
MASTER_SITES=	https://swarm.workshop.perforce.com/projects/perforce_software-jam/download/main/guest/perforce_software/${PORTNAME}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Build utility like make(1)
WWW=		https://www.perforce.com/jam/jam.html

LICENSE=	JAM
LICENSE_NAME=	jam license
LICENSE_TEXT=	License is hereby granted to use this software and distribute it freely, as long as this copyright notice is retained and modifications are clearly marked.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		zip

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
