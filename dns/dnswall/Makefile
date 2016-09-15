# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dnswall
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	dns security
MASTER_SITES=	GOOGLE_CODE LOCAL/ehaupt
PROJECTHOST=	google-dnswall

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Daemon that filters out private IP addresses in DNS responses

BROKEN=		Unfetchable (google code has gone away)

GNU_CONFIGURE=	yes
USES=		autoreconf dos2unix
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README
PLIST_FILES=	bin/dnswall

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
