PORTNAME=	dnscontrol
DISTVERSIONPREFIX=v
DISTVERSION=	4.7.2
CATEGORIES=	dns

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Synchronize your DNS to multiple providers from a simple DSL
WWW=		https://stackexchange.github.io/dnscontrol/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.21,modules
GO_MODULE=	github.com/StackExchange/dnscontrol/v4

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
