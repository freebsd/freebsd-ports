PORTNAME=	dnscontrol
DISTVERSIONPREFIX=v
DISTVERSION=	5.0.2
CATEGORIES=	dns

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Synchronize your DNS to multiple providers from a simple DSL
WWW=		https://dnscontrol.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.27,modules
GO_MODULE=	github.com/DNSControl/dnscontrol/v5

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
