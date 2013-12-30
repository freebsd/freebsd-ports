# Created by: db
# $FreeBSD$

PORTNAME=	locator
PORTVERSION=	0.1
CATEGORIES=	comms hamradio astro geography
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Grid square calculator program used in Amateur Radio and GPS work

CONFLICTS=	wwl*

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/locator ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
