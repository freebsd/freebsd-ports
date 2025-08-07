PORTNAME=	ergo
DISTVERSIONPREFIX=	v
DISTVERSION=	2.15.0
PORTREVISION=	4
CATEGORIES=	irc
PKGNAMESUFFIX=	-irc-server

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern IRC server (daemon/ircd) written in Go
WWW=		https://ergo.chat \
		https://github.com/ergochat/ergo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

USE_GITHUB=	yes
GH_ACCOUNT=	ergochat
GH_TUPLE=	golang:sys:v0.6.0:sys

CONFLICTS_INSTALL=	ergo

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
