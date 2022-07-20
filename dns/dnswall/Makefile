PORTNAME=	dnswall
PORTVERSION=	0.1.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	dns security

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Daemon that filters out private IP addresses in DNS responses

LICENSE=	APACHE20

GNU_CONFIGURE=	yes
USES=		autoreconf libtool dos2unix

USE_GITHUB=	yes
GH_ACCOUNT=	abarth
GH_PROJECT=	google-dnswall
GH_TAGNAME=	164174a

PORTDOCS=	README
PLIST_FILES=	bin/dnswall

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
