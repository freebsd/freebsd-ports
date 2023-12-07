PORTNAME=	dnsx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.6
PORTREVISION=	1
CATEGORIES=	dns

MAINTAINER=	nulldutra@proton.me
COMMENT=	DNS toolkit allow to run multiple DNS queries
WWW=		https://github.com/projectdiscovery/dnsx

LICENSE=	MIT

USES=		go:modules

GO_MODULE=	github.com/projectdiscovery/dnsx
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
