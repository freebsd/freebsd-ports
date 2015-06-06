# Created by: bkhl
# $FreeBSD$

PORTNAME=	sheerdns
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://threading.2038bug.com/sheerdns/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight, simple, and fast master DNS server

USES=		gmake

PLIST_FILES=	man/man8/sheerdns.8.gz sbin/sheerdns sbin/sheerdnshash

WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/sheerdns
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/sheerdnshash

.include <bsd.port.mk>
