PORTNAME=	cli53
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.25
PORTREVISION=	2
CATEGORIES=	dns

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Command line tool for Amazon Route 53
WWW=		https://github.com/barnybug/cli53

LICENSE=	MIT

USES=		go:modules
GO_MODULE=	github.com/barnybug/${PORTNAME}
GO_TARGET=	./cmd/cli53

PLIST_FILES=	bin/cli53

.include <bsd.port.mk>
