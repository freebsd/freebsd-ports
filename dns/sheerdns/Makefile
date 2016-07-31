# Created by: bkhl
# $FreeBSD$

PORTNAME=	sheerdns
PORTVERSION=	1.04
CATEGORIES=	dns
MASTER_SITES=	http://bsdforge.com/projects/source/dns/sheerdns/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Lightweight, simple, and fast master DNS server

LICENSE=	BSD2CLAUSE
LICENSE_FILES=	${WRKSRC}/LICENSE

DOCS=	sheerdns.ps sheerdns.html
PORTDOCS=	*

USES=		gmake tar:xz

PLIST_FILES=	man/man8/sheerdns.8.gz sbin/sheerdns sbin/sheerdnshash

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/sheerdns
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/sheerdnshash

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
