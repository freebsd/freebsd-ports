PORTNAME=	subfinder
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.7
PORTREVISION=	5
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Subdomain discovery tool that discovers valid subdomains for websites
WWW=		https://github.com/projectdiscovery/subfinder

LICENSE=	MIT

USES=		go:modules

GO_MODULE=	github.com/projectdiscovery/subfinder/v2
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
