# $FreeBSD$

PORTNAME=	oragono
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	irc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern IRC server (daemon/ircd) written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_TUPLE=	oragono:oragono-vendor:1deff6c:v/vendor

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
