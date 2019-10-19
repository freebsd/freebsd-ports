# Created by: bkhl
# $FreeBSD$

PORTNAME=	sheerdns
PORTVERSION=	1.04
CATEGORIES=	dns
MASTER_SITES=	https://BSDforge.com/projects/source/dns/sheerdns/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Lightweight, simple, and fast master DNS server

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake tar:xz

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	man/man8/sheerdns.8.gz sbin/sheerdns sbin/sheerdnshash
PORTDOCS=	sheerdns.html sheerdns.ps

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/sheerdns
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/sheerdnshash

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
