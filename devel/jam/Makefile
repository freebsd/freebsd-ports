# Created by: Jeffrey Hsu <hsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jam
PORTVERSION=	2.6
CATEGORIES=	devel
MASTER_SITES=	https://swarm.workshop.perforce.com/projects/perforce_software-jam/download/main/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Build utility like make(1)

USES=		zip

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
