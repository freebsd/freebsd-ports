# Created by: geniusj@ods.org
# $FreeBSD$

PORTNAME=	odsclient
PORTVERSION=	1.03
CATEGORIES=	dns
MASTER_SITES=	http://www.ods.org/dl/

MAINTAINER=	jd@ods.org
COMMENT=	ODS Dynamic DNS Client

ALL_TARGET=	odsclient

DEPRECATED=	ODS shuts service down, so client is probably useless
EXPIRATION_DATE=	2016-04-30

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/odsclient ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
