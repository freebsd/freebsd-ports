# $FreeBSD$

PORTNAME=	oragono
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	irc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern IRC server (daemon/ircd) written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_TUPLE=	oragono:oragono-vendor:1deff6c:v/vendor \
		golang:sys:fead79001313:golang_sys/vendor/golang.org/x/sys_fead79001313

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_fead79001313 ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
